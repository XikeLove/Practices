#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        u64 L, R;
        cin >> L >> R;
        u64 t1, t2;
        u64 r1, r2;
        u64 p;
        u64 ans = L;
        for (u64 i = 2; i <= 1000; i += 2) {
            p = pow(2, i);
            t1 = L / p;
            t2 = R / p;
            r1 = L % p;
            r2 = R % p;
            if (r1 <= r2 && r2 - r1 == R - L) {
                ans = L % p;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}