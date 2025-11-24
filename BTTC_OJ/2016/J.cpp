#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        map<int, long long> mp;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a;
            long long b;
            cin >> a >> b;
            mp[a] += b;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            long long cur = it->second;
            if (cur >= 3) {
                long long carry = cur / 3;
                long long remain = cur % 3;
                it->second = remain;
                mp[it->first + 1] += carry;
            }
        }

        long long ans = 0;
        for (auto &kv : mp) {
            ans += kv.second;
        }

        cout << "Case #" << cs << ":\n";
        cout << ans << "\n";
    }

    return 0;
}
