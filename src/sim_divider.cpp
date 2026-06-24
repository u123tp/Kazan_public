#include <verilated.h>
#include <verilated_vcd_c.h>

#include "Vsim_divider_top.h"

#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <string>
#include <vector>

enum class DivKind : uint8_t
{
    DIV = 0x42,
    DIVU = 0x43,
    REM = 0x44,
    REMU = 0x45,
    DIVW = 0x47,
    DIVUW = 0x48,
    REMW = 0x49,
    REMUW = 0x4A
};

static const char *kind_name(DivKind kind)
{
    switch (kind)
    {
    case DivKind::DIV:
        return "DIV";
    case DivKind::DIVU:
        return "DIVU";
    case DivKind::REM:
        return "REM";
    case DivKind::REMU:
        return "REMU";
    case DivKind::DIVW:
        return "DIVW";
    case DivKind::DIVUW:
        return "DIVUW";
    case DivKind::REMW:
        return "REMW";
    case DivKind::REMUW:
        return "REMUW";
    }

    return "UNKNOWN";
}

// 符号付き・符号なし間でビット列をそのまま移す。
// 範囲外のstatic_castに依存しないためmemcpyを使う。
static int64_t bits_to_i64(uint64_t value)
{
    int64_t result;
    static_assert(sizeof(result) == sizeof(value));
    std::memcpy(&result, &value, sizeof(result));
    return result;
}

static uint64_t i64_to_bits(int64_t value)
{
    uint64_t result;
    static_assert(sizeof(result) == sizeof(value));
    std::memcpy(&result, &value, sizeof(result));
    return result;
}

static int32_t bits_to_i32(uint32_t value)
{
    int32_t result;
    static_assert(sizeof(result) == sizeof(value));
    std::memcpy(&result, &value, sizeof(result));
    return result;
}

static uint32_t i32_to_bits(int32_t value)
{
    uint32_t result;
    static_assert(sizeof(result) == sizeof(value));
    std::memcpy(&result, &value, sizeof(result));
    return result;
}

static uint64_t sign_extend_32(uint32_t value)
{
    const int32_t signed32 = bits_to_i32(value);
    const int64_t signed64 = static_cast<int64_t>(signed32);
    return i64_to_bits(signed64);
}

/*
 * RISC-VのDIV/REM仕様に従った参照モデル。
 *
 * 除数0:
 *   DIV系 -> 全ビット1
 *   REM系 -> 被除数
 *
 * signed overflow:
 *   MIN_INT / -1 -> MIN_INT
 *   MIN_INT % -1 -> 0
 *
 * W命令:
 *   下位32bitで演算後、結果を64bitへ符号拡張
 */
static uint64_t reference_result(
    DivKind kind,
    uint64_t rs1,
    uint64_t rs2)
{
    switch (kind)
    {
    case DivKind::DIV:
    {
        const int64_t a = bits_to_i64(rs1);
        const int64_t b = bits_to_i64(rs2);

        if (b == 0)
        {
            return UINT64_MAX;
        }

        if (a == std::numeric_limits<int64_t>::min() && b == -1)
        {
            return i64_to_bits(std::numeric_limits<int64_t>::min());
        }

        return i64_to_bits(a / b);
    }

    case DivKind::DIVU:
    {
        if (rs2 == 0)
        {
            return UINT64_MAX;
        }

        return rs1 / rs2;
    }

    case DivKind::REM:
    {
        const int64_t a = bits_to_i64(rs1);
        const int64_t b = bits_to_i64(rs2);

        if (b == 0)
        {
            return rs1;
        }

        if (a == std::numeric_limits<int64_t>::min() && b == -1)
        {
            return 0;
        }

        return i64_to_bits(a % b);
    }

    case DivKind::REMU:
    {
        if (rs2 == 0)
        {
            return rs1;
        }

        return rs1 % rs2;
    }

    case DivKind::DIVW:
    {
        const uint32_t a_bits = static_cast<uint32_t>(rs1);
        const uint32_t b_bits = static_cast<uint32_t>(rs2);

        const int32_t a = bits_to_i32(a_bits);
        const int32_t b = bits_to_i32(b_bits);

        int32_t result;

        if (b == 0)
        {
            result = -1;
        }
        else if (
            a == std::numeric_limits<int32_t>::min() &&
            b == -1)
        {
            result = std::numeric_limits<int32_t>::min();
        }
        else
        {
            result = a / b;
        }

        return sign_extend_32(i32_to_bits(result));
    }

    case DivKind::DIVUW:
    {
        const uint32_t a = static_cast<uint32_t>(rs1);
        const uint32_t b = static_cast<uint32_t>(rs2);

        const uint32_t result =
            (b == 0) ? UINT32_MAX : (a / b);

        // DIVUWも結果は符号拡張される
        return sign_extend_32(result);
    }

    case DivKind::REMW:
    {
        const uint32_t a_bits = static_cast<uint32_t>(rs1);
        const uint32_t b_bits = static_cast<uint32_t>(rs2);

        const int32_t a = bits_to_i32(a_bits);
        const int32_t b = bits_to_i32(b_bits);

        int32_t result;

        if (b == 0)
        {
            result = a;
        }
        else if (
            a == std::numeric_limits<int32_t>::min() &&
            b == -1)
        {
            result = 0;
        }
        else
        {
            result = a % b;
        }

        return sign_extend_32(i32_to_bits(result));
    }

    case DivKind::REMUW:
    {
        const uint32_t a = static_cast<uint32_t>(rs1);
        const uint32_t b = static_cast<uint32_t>(rs2);

        const uint32_t result =
            (b == 0) ? a : (a % b);

        // REMUWも32bit結果を符号拡張する
        return sign_extend_32(result);
    }
    }

    std::cerr << "invalid DivKind\n";
    std::abort();
}

class DividerSim
{
public:
    DividerSim(int argc, char **argv, bool trace_enabled)
        : context_(std::make_unique<VerilatedContext>()),
          dut_(std::make_unique<Vsim_divider_top>(context_.get())),
          trace_enabled_(trace_enabled)
    {
        context_->commandArgs(argc, argv);
        context_->traceEverOn(trace_enabled_);

        if (trace_enabled_)
        {
            std::cerr
                << "--trace was requested, but Verilator was not built "
                   "with --trace\n";
        }

        dut_->clock = 0;
        dut_->reset = 0;
        dut_->flush_in = 0;
        dut_->req_valid = 0;
        dut_->req_opcode = 0;
        dut_->req_rs1 = 0;
        dut_->req_rs2 = 0;

        dut_->eval();
    }

    ~DividerSim()
    {
        dut_->final();
    }

    void tick()
    {
        dut_->clock = 1;
        dut_->eval();
        dump_trace();
        context_->timeInc(1);

        dut_->clock = 0;
        dut_->eval();
        dump_trace();
        context_->timeInc(1);
    }

    void reset()
    {
        dut_->req_valid = 0;
        dut_->flush_in = 0;

        dut_->reset = 1;
        tick();
        tick();

        dut_->reset = 0;
        tick();
    }

    /*
     * 1命令を投入し、resp_validまで待つ。
     *
     * 現在のDividerではPOST_PROC中にstall_outが0になる可能性があるため、
     * 応答確認後に1サイクル進め、確実にIDLEへ戻している。
     */
    bool execute(
        DivKind kind,
        uint64_t rs1,
        uint64_t rs2,
        uint64_t &result,
        unsigned &latency,
        unsigned timeout_cycles = 100)
    {
        unsigned wait_cycles = 0;

        // Dividerが空くまで待つ
        while (dut_->stall_out)
        {
            tick();

            if (++wait_cycles >= timeout_cycles)
            {
                std::cerr
                    << "[TIMEOUT] waiting for Divider idle\n";
                return false;
            }
        }

        // 入力を設定
        dut_->req_opcode = static_cast<uint8_t>(kind);
        dut_->req_rs1 = rs1;
        dut_->req_rs2 = rs2;
        dut_->req_valid = 1;

        // この立上りでDividerへ投入
        tick();

        dut_->req_valid = 0;

        latency = 0;

        while (latency < timeout_cycles)
        {
            if (dut_->resp_valid)
            {
                result = dut_->resp_value;

                const uint8_t returned_opcode =
                    static_cast<uint8_t>(dut_->resp_opcode);

                if (returned_opcode != static_cast<uint8_t>(kind))
                {
                    std::cerr
                        << "[ERROR] response opcode mismatch"
                        << " expected=0x"
                        << std::hex
                        << static_cast<unsigned>(
                               static_cast<uint8_t>(kind))
                        << " actual=0x"
                        << static_cast<unsigned>(returned_opcode)
                        << std::dec
                        << '\n';

                    return false;
                }

                // POST_PROCからIDLEへ戻す
                tick();

                return true;
            }

            tick();
            ++latency;
        }

        std::cerr
            << "[TIMEOUT] no response"
            << " opcode=0x"
            << std::hex
            << static_cast<unsigned>(
                   static_cast<uint8_t>(kind))
            << " rs1=0x"
            << rs1
            << " rs2=0x"
            << rs2
            << std::dec
            << '\n';

        return false;
    }

    /*
     * 実行途中でflushし、その後resp_validが出ないことを確認する。
     */
    bool test_flush(
        DivKind kind,
        uint64_t rs1,
        uint64_t rs2,
        unsigned cycles_before_flush = 3,
        unsigned observe_cycles = 80)
    {
        while (dut_->stall_out)
        {
            tick();
        }

        dut_->req_opcode = static_cast<uint8_t>(kind);
        dut_->req_rs1 = rs1;
        dut_->req_rs2 = rs2;
        dut_->req_valid = 1;
        tick();
        dut_->req_valid = 0;

        for (unsigned i = 0; i < cycles_before_flush; ++i)
        {
            tick();
        }

        dut_->flush_in = 1;
        tick();
        dut_->flush_in = 0;

        for (unsigned i = 0; i < observe_cycles; ++i)
        {
            if (dut_->resp_valid)
            {
                std::cerr
                    << "[FAIL] FLUSH produced a response"
                    << " opcode=" << kind_name(kind)
                    << " rs1=0x" << std::hex << rs1
                    << " rs2=0x" << rs2
                    << std::dec
                    << '\n';

                tick();
                return false;
            }

            tick();
        }

        return true;
    }

private:
    void dump_trace()
    {
    }

    std::unique_ptr<VerilatedContext> context_;
    std::unique_ptr<Vsim_divider_top> dut_;

    bool trace_enabled_;
};

struct TestOptions
{
    uint64_t seed = 4;
    unsigned random_tests_per_kind = 1000;
    unsigned max_failures = 20;
    bool trace = false;
    bool test_flush = true;
    bool print_success = false;
};

static void print_usage(const char *program_name)
{
    std::cerr
        << "Usage: " << program_name << " [options]\n"
        << "\n"
        << "Options:\n"
        << "  --trace                 enable VCD trace\n"
        << "  --skip-flush            skip flush test\n"
        << "  --print-success         print passed tests\n"
        << "  --seed <value>          random seed, default 1\n"
        << "  --random <value>        random tests per kind, default 1000\n"
        << "  --max-failures <value>  stop after this many failures, default 20\n";
}

static TestOptions parse_options(int argc, char **argv)
{
    TestOptions options;

    for (int i = 1; i < argc; ++i)
    {
        const std::string arg = argv[i];

        if (arg == "--trace")
        {
            options.trace = true;
        }
        else if (arg == "--skip-flush")
        {
            options.test_flush = false;
        }
        else if (arg == "--print-success")
        {
            options.print_success = true;
        }
        else if (arg == "--seed" && i + 1 < argc)
        {
            options.seed = std::stoull(argv[++i], nullptr, 0);
        }
        else if (arg == "--random" && i + 1 < argc)
        {
            options.random_tests_per_kind =
                static_cast<unsigned>(std::stoul(argv[++i], nullptr, 0));
        }
        else if (arg == "--max-failures" && i + 1 < argc)
        {
            options.max_failures =
                static_cast<unsigned>(std::stoul(argv[++i], nullptr, 0));
        }
        else if (arg == "--help" || arg == "-h")
        {
            print_usage(argv[0]);
            std::exit(EXIT_SUCCESS);
        }
        else
        {
            std::cerr << "[ERROR] unknown or incomplete option: " << arg << '\n';
            print_usage(argv[0]);
            std::exit(EXIT_FAILURE);
        }
    }

    return options;
}

static void print_failure(
    DivKind kind,
    uint64_t rs1,
    uint64_t rs2,
    uint64_t expected,
    uint64_t actual,
    unsigned latency)
{
    std::cerr
        << "\033[31m"
        << "[FAIL] " << kind_name(kind)
        << " rs1=0x" << std::hex << std::setw(16) << std::setfill('0') << rs1
        << " rs2=0x" << std::setw(16) << rs2
        << " expected=0x" << std::setw(16) << expected
        << " actual=0x" << std::setw(16) << actual
        << std::dec
        << " latency=" << latency
        << "\033[0m"
        << '\n';
}

static void print_success(
    DivKind kind,
    uint64_t rs1,
    uint64_t rs2,
    uint64_t result,
    unsigned latency)
{
    std::cerr
        << "\033[32m"
        << "[PASS] " << kind_name(kind)
        << " rs1=0x" << std::hex << std::setw(16) << std::setfill('0') << rs1
        << " rs2=0x" << std::setw(16) << rs2
        << " result=0x" << std::setw(16) << result
        << std::dec
        << " latency=" << latency
        << "\033[0m"
        << '\n';
}

int main(int argc, char **argv)
{
    const TestOptions options = parse_options(argc, argv);

    DividerSim sim(argc, argv, options.trace);
    sim.reset();

    const std::array<DivKind, 8> kinds = {
        DivKind::DIV,
        DivKind::DIVU,
        DivKind::REM,
        DivKind::REMU,
        DivKind::DIVW,
        DivKind::DIVUW,
        DivKind::REMW,
        DivKind::REMUW};

    // 0除算、符号境界、32bit境界、ビットパターンを含める
    const std::vector<uint64_t> edge_values = {
        0x0000000000000000ULL,
        0x0000000000000001ULL,
        0x0000000000000002ULL,
        0x0000000000000003ULL,
        0x0000000000000004ULL,
        0x0000000000000007ULL,
        0x0000000000000008ULL,
        0x000000000000000FULL,

        0x000000007FFFFFFFULL,
        0x0000000080000000ULL,
        0x00000000FFFFFFFFULL,
        0x0000000100000000ULL,

        0x7FFFFFFFFFFFFFFFULL,
        0x8000000000000000ULL,
        0x8000000000000001ULL,
        0xFFFFFFFF00000000ULL,
        0xFFFFFFFF7FFFFFFFULL,
        0xFFFFFFFF80000000ULL,
        0xFFFFFFFFFFFFFFFDULL,
        0xFFFFFFFFFFFFFFFEULL,
        0xFFFFFFFFFFFFFFFFULL,

        0xAAAAAAAAAAAAAAAAULL,
        0x5555555555555555ULL,
        0x0123456789ABCDEFULL,
        0xFEDCBA9876543210ULL};

    uint64_t total_tests = 0;
    uint64_t failures = 0;

    auto run_test =
        [&](DivKind kind, uint64_t rs1, uint64_t rs2) -> bool
    {
        ++total_tests;

        const uint64_t expected =
            reference_result(kind, rs1, rs2);

        uint64_t actual = 0;
        unsigned latency = 0;

        if (!sim.execute(kind, rs1, rs2, actual, latency))
        {
            std::cerr
                << "[TIMEOUT] " << kind_name(kind)
                << " rs1=0x" << std::hex << std::setw(16) << std::setfill('0') << rs1
                << " rs2=0x" << std::setw(16) << rs2
                << std::dec << '\n';

            ++failures;
            return false;
        }

        if (actual != expected)
        {
            print_failure(
                kind,
                rs1,
                rs2,
                expected,
                actual,
                latency);

            ++failures;
            return false;
        }

        if (options.print_success)
        {
            print_success(
                kind,
                rs1,
                rs2,
                actual,
                latency);
        }

        return true;
    };

    // ランダム試験
    printf("------------------------------------------ランダム試験---------------------------------------\n");
    std::mt19937_64 random(options.seed);

    for (const DivKind kind : kinds)
    {
        std::cout
            << "[RANDOM] "
            << kind_name(kind)
            << " count="
            << options.random_tests_per_kind
            << '\n';

        for (unsigned i = 0;
             i < options.random_tests_per_kind;
             ++i)
        {
            uint64_t rs1 = random();
            uint64_t rs2 = random();

            // 一定間隔で特殊ケースも混ぜる
            switch (i % 16)
            {
            case 0:
                rs2 = 0;
                break;

            case 1:
                rs2 = UINT64_MAX;
                break;

            case 2:
                rs1 = 0x8000000000000000ULL;
                rs2 = UINT64_MAX;
                break;

            case 3:
                rs1 = 0x0000000080000000ULL;
                rs2 = 0x00000000FFFFFFFFULL;
                break;

            default:
                break;
            }

            run_test(kind, rs1, rs2);

            if (failures >= options.max_failures)
            {
                std::cerr
                    << "stopped after "
                    << failures
                    << " failures\n";

                std::cout
                    << '\n'
                    << "tests    : " << total_tests << '\n'
                    << "failures : " << failures << '\n'
                    << "seed     : " << options.seed << '\n';

                return EXIT_FAILURE;
            }
        }
    }

    // 結果表示
    printf("-----------------------------結果-------------------------------------------------------");
    std::cout
        << '\n'
        << "tests    : " << total_tests << '\n'
        << "failures : " << failures << '\n'
        << "seed     : " << options.seed << '\n';

    if (failures == 0)
    {
        std::cout << "[PASS] all divider tests passed\n";
        return EXIT_SUCCESS;
    }

    std::cout << "[FAIL] divider test failed\n";
    return EXIT_FAILURE;
}