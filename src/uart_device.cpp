// uartのデバイス（C++側）
// svから標準入出力をuartの入出力として使用できるように.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static bool inited = false;

// デフォルトだと,read()は入力がなければ入力が来るまで待つが,scan_char()は毎サイクル
// 結果を返さないといけないのでそれではいけない.
// O_NONBLOCKをfcntlで設定すると,read()は入力がなければ,ブロックする代わりに-1を返すようになる.
static void init_nonblock()
{
    if (inited)
        return;
    int flags = fcntl(0, F_GETFL, 0);
    if (flags >= 0)
        fcntl(0, F_SETFL, flags | O_NONBLOCK);
    inited = true;
}

extern "C" void print_char(int ch)
{
    unsigned char c = (unsigned char)ch;
    write(1, &c, 1);
}

extern "C" int scan_char()
{
    init_nonblock();
    unsigned char c;
    ssize_t n = read(0, &c, 1);
    return (n == 1) ? (int)c : -1;
}