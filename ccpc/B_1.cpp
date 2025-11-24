// #include <bits/stdc++.h>
// using namespace std;

// static const int MAXN = 110;
// static const int MAXC = 405;

// int mp[MAXN][MAXC];
// int dista[MAXN][MAXC];

// const int DX[2][3] = {
//     {0, 0, 1}, // op=0：左、右、下中
//     {0, 0, 1}, // op=1：左、右、下中
// };
// const int DY[2][3] = {
//     {-1, 1, 0}, // op=0
//     {-1, 1, 0}, // op=1
// };

// // REQ[op][cur][dir]：列内奇偶=op 时，从当前格(底面=cur)朝 dir(0左1右2斜)滚过去，邻格必须等于的数字
// const int REQ[2][5][3] = {{// op = 0（偶）
//                            /*0*/ {0, 0, 0},
//                            /*1*/ {2, 4, 3},
//                            /*2*/ {1, 3, 4},
//                            /*3*/ {4, 2, 1},
//                            /*4*/ {3, 1, 2}},
//                           {// op = 1（奇）
//                            /*0*/ {0, 0, 0},
//                            /*1*/ {4, 2, 3},
//                            /*2*/ {3, 1, 4},
//                            /*3*/ {2, 4, 1},
//                            /*4*/ {1, 3, 2}}};

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n))
//         return 0;

//     // 第1行唯一格子的中心列坐标
//     int mx = (1 + (n - 1) * 2);
//     mx = mx / 2 + 1;

//     // 读入三角形（其余位置为 0）
//     for (int i = 1; i <= n; ++i) {
//         int len = 1 + (i - 1) * 2;
//         int be = mx - len / 2;
//         for (int j = 0; j < len; ++j) {
//             int y = be + j;
//             cin >> mp[i][y];
//         }
//     }

//     int tx, ty;
//     cin >> tx >> ty;

//     int len = 1 + (tx - 1) * 2;
//     int be = mx - len / 2;
//     ty = be + (ty - 1);

//     for (int i = 0; i < MAXN; ++i)
//         for (int j = 0; j < MAXC; ++j)
//             dista[i][j] = -1;

//     queue<pair<int, int>> q;
//     dista[1][mx] = 0;
//     q.push({1, mx});

//     while (!q.empty()) {
//         auto [i, y] = q.front();
//         q.pop();
//         if (i == tx && y == ty)
//             break;

//         int cur = mp[i][y];
//         if (cur < 1 || cur > 4)
//             continue;

//         int len = 1 + (i - 1) * 2;
//         int be = mx - len / 2;
//         int op = ((y - be) & 1) ^ 1;

//         for (int dir = 0; dir < 3; ++dir) {
//             int ni = i + DX[op][dir];
//             int ny = y + DY[op][dir];
//             if (ni < 1 || ni > n)
//                 continue;
//             if (ny < 1 || ny >= MAXC)
//                 continue;
//             if (mp[ni][ny] == 0)
//                 continue;

//             if (mp[ni][ny] == REQ[op][cur][dir]) {
//                 if (dista[ni][ny] == -1) {
//                     dista[ni][ny] = dista[i][y] + 1;
//                     q.push({ni, ny});
//                 }
//             }
//         }
//     }

//     cout << dista[tx][ty] << '\n';
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 110;
static const int MAXC = 405;

int mp[MAXN][MAXC];
int dista[MAXN][MAXC];

// 三个方向：0 左，1 右，2 竖直（沿三角形中线那条边）
// 注意：对“朝下”的小三角（op=0），竖直邻居在上一行；对“朝上”的小三角（op=1），竖直邻居在下一行。
const int DX[2][3] = {
    {0, 0, -1}, // op=0：左、右、上
    {0, 0,  1}, // op=1：左、右、下
};
const int DY[2][3] = {
    {-1, 1, 0}, // op=0
    {-1, 1, 0}, // op=1
};

// REQ[op][cur][dir]：列内奇偶=op 时，从当前格(底面=cur)朝 dir(0左1右2竖直)滚过去，邻格必须等于的数字
const int REQ[2][5][3] = {{
// op = 0（朝下小三角）
/*0*/ {0, 0, 0},
/*1*/ {2, 4, 3},
/*2*/ {1, 3, 4},
/*3*/ {4, 2, 1},
/*4*/ {3, 1, 2}},
{ // op = 1（朝上小三角）
/*0*/ {0, 0, 0},
/*1*/ {4, 2, 3},
/*2*/ {3, 1, 4},
/*3*/ {2, 4, 1},
/*4*/ {1, 3, 2}}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // 顶行唯一格子的中心列坐标
    int mx = (1 + (n - 1) * 2);
    mx = mx / 2 + 1; // 等价于 n

    // 读入三角形（其余位置为 0）
    for (int i = 1; i <= n; ++i) {
        int len = 1 + (i - 1) * 2;
        int be = mx - len / 2;
        for (int j = 0; j < len; ++j) {
            int y = be + j;
            cin >> mp[i][y];
        }
    }

    int tx, ty;
    cin >> tx >> ty;

    int len = 1 + (tx - 1) * 2;
    int be = mx - len / 2;
    ty = be + (ty - 1);

    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXC; ++j)
            dista[i][j] = -1;

    queue<pair<int,int>> q;
    dista[1][mx] = 0;
    q.push({1, mx});

    while (!q.empty()) {
        auto [i, y] = q.front();
        q.pop();
        if (i == tx && y == ty) break;

        int cur = mp[i][y];
        if (cur < 1 || cur > 4) continue;

        int len = 1 + (i - 1) * 2;
        int be = mx - len / 2;
        // 行内索引奇偶：j = y - be。j 偶（朝上）=> op=1；j 奇（朝下）=> op=0
        int op = ((y - be) & 1) ^ 1;

        for (int dir = 0; dir < 3; ++dir) {
            int ni = i + DX[op][dir];
            int ny = y + DY[op][dir];
            if (ni < 1 || ni > n) continue;
            if (ny < 1 || ny >= MAXC) continue;
            if (mp[ni][ny] == 0) continue;

            if (mp[ni][ny] == REQ[op][cur][dir]) {
                if (dista[ni][ny] == -1) {
                    dista[ni][ny] = dista[i][y] + 1;
                    q.push({ni, ny});
                }
            }
        }
    }

    cout << dista[tx][ty] << '\n';
    return 0;
}
