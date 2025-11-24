#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<i64, i64>> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i].first >> a[i].second;

        sort(a.begin(), a.end());

        i64 maxY = LLONG_MIN;
        vector<pair<i64, i64>> ans;
        for (int i = n - 1; i >= 0; --i) {
            i64 x = a[i].first, y = a[i].second;
            if (y > maxY) {
                ans.push_back(a[i]);
                maxY = y;
            }
        }
        reverse(ans.begin(), ans.end());

        for (auto &p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}
