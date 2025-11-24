#include <bits/stdc++.h>
using namespace std;

int n;

struct Sj {
    int flag;
    int value;
    int z_val;
    int bs;
    bool bj;
};

Sj sjs[105][105];

void f(int i, int j, int zval) {
    if (sjs[i][j].bj)
        return;
    sjs[i][j].z_val = zval;
    sjs[i][j].bj = true;
    if (sjs[i][j].flag == 0) { //反三角确定三个值
        if (i - 1 >= 1 && j - 1 >= 1) {
            int nval;
            if (zval == 1)
                nval = 3;
            else if (zval == 2)
                nval = 4;
            else if (zval == 3)
                nval = 1;
            else if (zval == 4)
                nval = 2;
            f(i - 1, j - 1, nval);
        }
        if (j - 1 > 1) {
            int nval;
            if (zval == 1)
                nval = 2;
            else if (zval == 2)
                nval = 1;
            else if (zval == 3)
                nval = 4;
            else if (zval == 4)
                nval = 3;
            f(i, j - 1, nval);
        }
        if (j + 1 <= n) {
            int nval;
            if (zval == 1)
                nval = 4;
            else if (zval == 2)
                nval = 3;
            else if (zval == 3)
                nval = 2;
            else if (zval == 4)
                nval = 1;
            f(i, j + 1, nval);
        }
    } else { //正三角确定三个值
        if (i + 1 <= n && j + 1 <= n) {
            int nval;
            if (zval == 1)
                nval = 3;
            else if (zval == 2)
                nval = 4;
            else if (zval == 3)
                nval = 1;
            else if (zval == 4)
                nval = 2;
            f(i - 1, j - 1, nval);
        }
        if (j - 1 > 1) {
            int nval;
            if (zval == 1)
                nval = 4;
            else if (zval == 2)
                nval = 3;
            else if (zval == 3)
                nval = 2;
            else if (zval == 4)
                nval = 1;
            f(i, j - 1, nval);
        }
        if (j + 1 <= n) {
            int nval;
            if (zval == 1)
                nval = 2;
            else if (zval == 2)
                nval = 1;
            else if (zval == 3)
                nval = 4;
            else if (zval == 4)
                nval = 3;
            f(i, j + 1, nval);
        }
    }
}

int main() {
    cin >> n;
    int x, y;
    int bs = 0;
    sjs[1][1].bs = 0;
    //对sjs[1][1]初始化
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> sjs[i][j].value; //存值
            if (j % 2 == 0)
                sjs[i][j].flag = 0; //判断是正三角还是反三角
            else
                sjs[i][j].flag = 1;
            if (sjs[i][j].flag == 0)
                sjs[i][j].bs = bs + 1; //更新步数
            else
                sjs[i][j].bs = bs + 2;
            sjs[i][j].bj = false; //初始化标记为未被更新
        }
        bs += 2;
    }
    cin >> x >> y;

    f(1, 1, 4);

    if (sjs[x][y].value == sjs[x][y].z_val)
        cout << sjs[x][y].bs;
    else
        cout << "-1";
}