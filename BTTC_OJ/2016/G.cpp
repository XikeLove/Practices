#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    a = llabs(a);
    b = llabs(b);
    while (b != 0) {
        i64 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 X1, Y1, R1, X2, Y2, R2;
    i64 W1;
    while (cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2 >> W1) {
        i64 extDis = llabs(R1 + R2);
        i64 inDis = llabs(R1 - R2);
        i64 r12_x = (X1 - X2) * (X1 - X2);
        i64 r12_y = (Y1 - Y2) * (Y1 - Y2);
        i64 Dis = r12_x + r12_y;
        if (Dis == extDis * extDis) {
            //外切
            i64 fenzi = -R1 * W1;
            i64 fenmu = R2;
            if (fenmu < 0)
                fenzi *= -1;
            i64 gcdNum = gcd(fenzi, fenmu);
            fenzi /= gcdNum;
            fenmu /= gcdNum;
            if (fenmu == 1) {
                cout << fenzi << "\n";
            } else {
                cout << fenzi << "/" << fenmu << "\n";
            }
        } else if (Dis == inDis * inDis) {
            //内切
            i64 fenzi = R1 * W1;
            i64 fenmu = R2;
            if (fenmu < 0)
                fenzi *= -1;
            i64 gcdNum = gcd(fenzi, fenmu);
            fenzi /= gcdNum;
            fenmu /= gcdNum;
            if (fenmu == 1) {
                cout << fenzi << "\n";
            } else {
                cout << fenzi << "/" << fenmu << "\n";
            }
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}