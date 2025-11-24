#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int gcd(i64 a, i64 b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--) {
        i64 a, b;
        cin >> a >> b;
        i64 g = gcd(a, b);
        if (g == 1) {
            cout << -1 << '\n';
            continue;
        }

        vector<i64> d;
        for (i64 i = 1; i <= sqrt(g); i++) {
            if (g % i == 0) {
                d.push_back(i);
                if (i * i != g)
                    d.push_back(g / i);
            }
        }
        sort(d.begin(), d.end(), greater<i64>());
        if (d.size() < 3)
            cout << -1 << '\n';
        else
            cout << d[2] << '\n';
    }
    return 0;
}
