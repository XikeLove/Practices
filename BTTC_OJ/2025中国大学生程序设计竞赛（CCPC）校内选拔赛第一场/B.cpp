#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

int S(int n) {
    int ans = 0;
    int t = n;
    while (t) {
        ans += t % 10;
        t /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    u64 n;
    while (cin >> n) {
        u64 ans = 10;
        //枚举S(x)
        for (int sx = 1; sx <= 162; sx++) {
            //二分枚举x
            u64 l = 1;
            u64 r = sqrt(n);
            while (l + 1 <= r) {
                u64 mid = (l + r) / 2;
                u64 res = mid * mid + sx * mid;
                if (res >= n) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            //l就是x
            if (l * l + sx * l == n) {
                if (S(l) == sx) {
                    ans = l;
                }
            }
        }
        if (ans * ans + S(ans) * ans == n) {
            cout << ans << "\n";
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
