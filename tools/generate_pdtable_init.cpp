
// generate_pdtable_init.cpp
//
// pdtable.hexを読み込み、SystemVerilog用の初期化コードを生成する。
//
// pdtable.hex:
//   行方向: table_pri
//   列方向: table_d
//
// SystemVerilogの配列:
//   pdtable[table_d][table_pri]
//
// 使用例:
//   g++ -std=c++17 -O2 generate_pdtable_init.cpp -o generate_pdtable_init
//   ./generate_pdtable_init pdtable.hex pdtable_init.svh

#include <cctype>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{

    using Table = std::vector<std::vector<unsigned int>>;

    Table read_table(const std::string &filename)
    {
        std::ifstream input(filename);

        if (!input)
        {
            throw std::runtime_error(
                "cannot open input file: " + filename);
        }

        Table table;
        std::size_t expected_columns = 0;

        std::string line;
        std::size_t line_number = 0;

        while (std::getline(input, line))
        {
            ++line_number;

            std::vector<unsigned int> row;

            for (const unsigned char ch : line)
            {
                if (std::isspace(ch))
                {
                    continue;
                }

                // 現在のテーブルでは0, 1, 2, 3のみを許可する。
                if (ch < '0' || ch > '3')
                {
                    throw std::runtime_error(
                        "invalid character at line " +
                        std::to_string(line_number) +
                        ": '" +
                        std::string(1, static_cast<char>(ch)) +
                        "'");
                }

                row.push_back(
                    static_cast<unsigned int>(ch - '0'));
            }

            // 空行は無視する。
            if (row.empty())
            {
                continue;
            }

            if (expected_columns == 0)
            {
                expected_columns = row.size();
            }
            else if (row.size() != expected_columns)
            {
                throw std::runtime_error(
                    "column count mismatch at line " +
                    std::to_string(line_number) +
                    ": expected " +
                    std::to_string(expected_columns) +
                    ", but got " +
                    std::to_string(row.size()));
            }

            table.push_back(std::move(row));
        }

        if (table.empty())
        {
            throw std::runtime_error(
                "input file contains no table data");
        }

        return table;
    }

    void write_systemverilog(
        const Table &table,
        const std::string &filename)
    {
        std::ofstream output(filename);

        if (!output)
        {
            throw std::runtime_error(
                "cannot open output file: " + filename);
        }

        const std::size_t pri_count = table.size();
        const std::size_t d_count = table.front().size();

        output
            << "// Automatically generated file.\n"
            << "// Do not edit manually.\n"
            << "//\n"
            << "// Number of d entries  : " << d_count << "\n"
            << "// Number of pri entries: " << pri_count << "\n"
            << "// Index order: pdtable[table_d][table_pri]\n\n";

        output << "initial begin : init_pdtable\n";

        for (std::size_t table_d = 0;
             table_d < d_count;
             ++table_d)
        {
            output << "    // table_d = " << table_d << "\n";

            for (std::size_t table_pri = 0;
                 table_pri < pri_count;
                 ++table_pri)
            {
                output
                    << "    pdtable["
                    << table_d
                    << "]["
                    << table_pri
                    << "] = 2'd"
                    << table[table_pri][table_d]
                    << ";\n";
            }

            output << "\n";
        }

        output << "end\n";
    }

} // namespace

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2 || argc > 3)
        {
            std::cerr
                << "Usage:\n"
                << "  " << argv[0]
                << " <input.hex> [output.svh]\n\n"
                << "Example:\n"
                << "  " << argv[0]
                << " pdtable.hex pdtable_init.svh\n";

            return 1;
        }

        const std::string input_filename = argv[1];

        const std::string output_filename =
            argc == 3
                ? argv[2]
                : "pdtable_init.svh";

        const Table table = read_table(input_filename);

        write_systemverilog(
            table,
            output_filename);

        std::cout
            << "Generated " << output_filename << '\n'
            << "  d entries  : " << table.front().size() << '\n'
            << "  pri entries: " << table.size() << '\n'
            << "  index order: pdtable[d][pri]\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}