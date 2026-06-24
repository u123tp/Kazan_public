// xv6-riscv user program: 2048
// 操作: w/a/s/d + Enter (または k/h/j/l + Enter), q=quit, r=restart

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define N 4

static int board[N][N];
static int score;

// ---- 小さな乱数 (xorshift64) ----
static uint64 rng_state;

static uint64 xorshift64(void)
{
    uint64 x = rng_state;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    rng_state = x;
    return x;
}

static int rand_int(int mod)
{ // 0..mod-1
    if (mod <= 0)
        return 0;
    return (int)(xorshift64() % (uint64)mod);
}

// ---- 盤面ユーティリティ ----
static void clear_board(void)
{
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            board[y][x] = 0;
    score = 0;
}

static int count_empty(void)
{
    int c = 0;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (board[y][x] == 0)
                c++;
    return c;
}

static void add_random_tile(void)
{
    int empty = count_empty();
    if (empty == 0)
        return;

    int k = rand_int(empty);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (board[y][x] == 0)
            {
                if (k == 0)
                {
                    // 90%:2, 10%:4
                    int v = (rand_int(10) == 0) ? 4 : 2;
                    board[y][x] = v;
                    return;
                }
                k--;
            }
        }
    }
}

static int can_move(void)
{
    if (count_empty() > 0)
        return 1;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            int v = board[y][x];
            if (x + 1 < N && board[y][x + 1] == v)
                return 1;
            if (y + 1 < N && board[y + 1][x] == v)
                return 1;
        }
    }
    return 0;
}

// ---- 行(4要素)を左に詰めてマージする ----
// 戻り値: 変更があったら 1
static int slide_merge_left(int line[4])
{
    int orig[4];
    for (int i = 0; i < 4; i++)
        orig[i] = line[i];

    // compress
    int tmp[4] = {0, 0, 0, 0};
    int t = 0;
    for (int i = 0; i < 4; i++)
    {
        if (line[i] != 0)
            tmp[t++] = line[i];
    }

    // merge
    for (int i = 0; i < 3; i++)
    {
        if (tmp[i] != 0 && tmp[i] == tmp[i + 1])
        {
            tmp[i] *= 2;
            score += tmp[i];
            tmp[i + 1] = 0;
            i++; // 次はスキップ
        }
    }

    // compress again
    int out[4] = {0, 0, 0, 0};
    t = 0;
    for (int i = 0; i < 4; i++)
    {
        if (tmp[i] != 0)
            out[t++] = tmp[i];
    }

    int changed = 0;
    for (int i = 0; i < 4; i++)
    {
        line[i] = out[i];
        if (line[i] != orig[i])
            changed = 1;
    }
    return changed;
}

// dir: 0=left,1=right,2=up,3=down
static int move_dir(int dir)
{
    int changed = 0;
    int line[4];

    if (dir == 0)
    { // left
        for (int y = 0; y < N; y++)
        {
            for (int i = 0; i < 4; i++)
                line[i] = board[y][i];
            if (slide_merge_left(line))
                changed = 1;
            for (int i = 0; i < 4; i++)
                board[y][i] = line[i];
        }
    }
    else if (dir == 1)
    { // right
        for (int y = 0; y < N; y++)
        {
            for (int i = 0; i < 4; i++)
                line[i] = board[y][3 - i];
            if (slide_merge_left(line))
                changed = 1;
            for (int i = 0; i < 4; i++)
                board[y][3 - i] = line[i];
        }
    }
    else if (dir == 2)
    { // up
        for (int x = 0; x < N; x++)
        {
            for (int i = 0; i < 4; i++)
                line[i] = board[i][x];
            if (slide_merge_left(line))
                changed = 1;
            for (int i = 0; i < 4; i++)
                board[i][x] = line[i];
        }
    }
    else if (dir == 3)
    { // down
        for (int x = 0; x < N; x++)
        {
            for (int i = 0; i < 4; i++)
                line[i] = board[3 - i][x];
            if (slide_merge_left(line))
                changed = 1;
            for (int i = 0; i < 4; i++)
                board[3 - i][x] = line[i];
        }
    }

    return changed;
}

static void draw(void)
{
    // ANSI clear (効かない環境ならただ流れるだけ)
    printf("\x1b[H\x1b[2J");
    printf("2048 on xv6 | score=%d\n", score);
    printf("controls: w/a/s/d (or k/h/j/l) + Enter, r=restart, q=quit\n\n");

    for (int y = 0; y < N; y++)
    {
        printf("+------+------+------+------+\n");
        for (int x = 0; x < N; x++)
        {
            int v = board[y][x];
            if (v == 0)
            {
                printf("|      ");
            }
            else if(v==2 || v== 4 || v== 8)
            {
                printf("|   %d  ", v);
            }else if(v== 16 || v== 32 || v== 64){
                printf("|  %d  ", v);
            } else if(v== 128 || v== 256 || v== 512){
                printf("|  %d ", v);
            } else {
                printf("|  %d ", v);
            }
        }
        printf("|\n");
    }
    printf("+------+------+------+------+\n");

    if (!can_move())
    {
        printf("\nGAME OVER. (r=restart, q=quit)\n");
    }
}

static int read_cmd(void)
{
    char buf[32];
    // xv6 の gets は Enter まで待つ
    if (gets(buf, sizeof(buf)) == 0)
        return 'q';
    if (buf[0] == 0)
        return 0;
    return buf[0];
}

int main(void)
{
    // seed
    rng_state = ((uint64)uptime() << 32) ^ (uint64)getpid() ^ 0x9e3779b97f4a7c15ULL;
    clear_board();
    add_random_tile();
    add_random_tile();

    for (;;)
    {
        draw();

        printf("\n> ");
        int c = read_cmd();
        if (c == 0)
            continue;

        if (c == 'q' || c == 'Q')
            break;
        if (c == 'r' || c == 'R')
        {
            clear_board();
            add_random_tile();
            add_random_tile();
            continue;
        }

        int dir = -1;
        if (c == 'a' || c == 'h' || c == 'A' || c == 'H')
            dir = 0;
        if (c == 'd' || c == 'l' || c == 'D' || c == 'L')
            dir = 1;
        if (c == 'w' || c == 'k' || c == 'W' || c == 'K')
            dir = 2;
        if (c == 's' || c == 'j' || c == 'S' || c == 'J')
            dir = 3;

        if (dir >= 0)
        {
            int before_score = score;
            int changed = move_dir(dir);
            if (changed)
            {
                add_random_tile();
            }
            else
            {
                // スコアだけ動いてないはずだが念のため
                score = before_score;
            }
        }
    }

    printf("bye.\n");
    exit(0);
}
