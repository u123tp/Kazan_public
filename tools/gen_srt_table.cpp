// srtのテーブルを作成.
// 変数名とかはおおよそ以下のレポートに準拠.
// http://i.stanford.edu/pub/cstr/reports/csl/tr/95/679/CSL-TR-95-679.pdf

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cmath>

class Fraction
{
private:
    long long nume;
    long long deno;

    // 約分
    void normalize()
    {
        if (deno == 0)
        {
            throw std::runtime_error("denominator is zero");
        }
        if (deno < 0)
        {
            nume = -nume;
            deno = -deno;
        }
        long long g = std::gcd(nume, deno);
        nume /= g;
        deno /= g;
    }

public:
    Fraction(long long n = 0, long long d = 1)
        : nume(n), deno(d)
    {
        normalize();
    }

    Fraction operator+(const Fraction &rhs) const
    {
        return Fraction(
            nume * rhs.deno + rhs.nume * deno,
            deno * rhs.deno);
    }

    Fraction operator-(const Fraction &rhs) const
    {
        return Fraction(
            nume * rhs.deno - rhs.nume * deno,
            deno * rhs.deno);
    }

    Fraction operator*(const Fraction &rhs) const
    {
        return Fraction(
            nume * rhs.nume,
            deno * rhs.deno);
    }

    Fraction operator/(const Fraction &rhs) const
    {
        if (rhs.nume == 0)
        {
            throw std::runtime_error("division by zero");
        }

        return Fraction(
            nume * rhs.deno,
            deno * rhs.nume);
    }

    long long denominator() const noexcept
    {
        return deno;
    }

    long long numerator() const noexcept
    {
        return nume;
    }
};

int main()
{
    // 除数のビット長(ただし除数はunsigned)
    constexpr int d_len = 64;

    // 商選択で用いるd,priの上位ビットの長さ.
    // ただし,dは正規化した際の最上位ビットを除いた長さ,ｐriは符号ビットを除いた長さ.
    // これはpdデーブルのサイズを基準としているためこのように取る.
    constexpr int table_d_len = 5;
    constexpr int table_pri_len = 7;

    // dpグラフについて,
    // priが正であれば,そのpriとdが誤差を辺として作成される長方形が取りうる商を取ることにする.
    // ここで言う長方形とは,dpの大きさは(2^selector_d_len)*(2^selector_pri_len)であるが,
    // あくまで上位ビットだけ切り取ったものの表であるため,その中にはdとpriの組み合わせが多数あるため.
    // ただし,この長方形の一番左上に属する(d,pri)と右下に属する(d,pri)が同じ商を取らなければ不正となり,
    // そもそもこの表の作成は不可能である.
    // priが負は正をひっくり返すだけなので,このdpには記載しない.
    int dp[1 << table_pri_len][1 << table_d_len];
    constexpr int invalid = 3;

    for (auto &row : dp)
    {
        for (auto &value : row)
        {
            value = invalid;
        }
    }

    // Ukが上限,Lkが下限.indexが商の値(ただし0以上のみ.負は後で反転させて作成するので.)
    constexpr int r = 4; // radix-r
    constexpr int log2r = 2;
    static_assert((1 << log2r) == r, "r must equal 2^log2r");

    constexpr int a = 2; // 商が{-a,-a+1, ... ,a-1,a}

    // 冗長度係数
    Fraction rho(a, r - 1);

    // それぞれの商範囲を指定.priについて, Lk*d < 4pri < Uk*d を取る.
    // ここで, Uk=(ρ+k), Lk=(-ρ+k) とする.
    Fraction l[a + 1];
    Fraction u[a + 1];
    for (int i = 0; i < a + 1; i++)
    {
        l[i] = Fraction(i) - rho;
        u[i] = Fraction(i) + rho;
    }

    // 4priは0 <= 4pri < 8とする。
    // 整数部のビット数.dは正規化されて1<=d<2であるため,それの2^r倍まで表せる必要がある.
    constexpr int pri_integer_len = 1 + log2r;
    // 切り捨てた4priの長さ.
    constexpr int pri_lower_len =
        d_len + pri_integer_len - table_pri_len;

    for (__int128_t table_d = 0;
         table_d < (static_cast<__int128_t>(1) << table_d_len);
         table_d++)
    {
        for (__int128_t table_pri = 0;
             table_pri < (static_cast<__int128_t>(1) << table_pri_len);
             table_pri++)
        {
            // d = 1.xxxxx...として正規化されている。
            __int128_t d_min =
                (static_cast<__int128_t>(1) << d_len) +
                (table_d << (d_len - table_d_len));

            __int128_t d_max =
                d_min +
                (static_cast<__int128_t>(1)
                 << (d_len - table_d_len)) -
                1;

            // 4priの上位table_pri_lenビットがtable_priである範囲。
            __int128_t pri_min =
                table_pri << pri_lower_len;

            __int128_t pri_max =
                pri_min + (static_cast<__int128_t>(1) << pri_lower_len) - 1;

            for (int i = 0; i < a + 1; i++)
            {
                // セル全体が
                //     L_i d < 4pri < U_i d
                // に含まれるか調べる。
                if (pri_max * u[i].denominator() <
                        d_min * u[i].numerator() &&
                    pri_min * l[i].denominator() >
                        d_max * l[i].numerator())
                {
                    dp[table_pri][table_d] = i;
                    break;
                }
            }
        }
    }

    FILE *fp = fopen("pdtable.hex", "w");
    // 出力
    for (int table_pri = 0;
         table_pri < (1 << table_pri_len);
         table_pri++)
    {
        for (int table_d = 0; table_d < (1 << table_d_len); table_d++)
        {
            fprintf(fp, "%d", dp[table_pri][table_d]);
        }
        fprintf(fp, "\n");
    }
}