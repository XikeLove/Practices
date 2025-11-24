#include <bits/stdc++.h>
using namespace std;
int t;

void solve() {
    string s;
    cin >> s;
    if (t == 1) {
        cout << s << "\n";
        return;
    }
    map<char, int> mp;
    for (auto ch : s) {
        mp[ch]++;
    }
    string ans = "";
    for (auto it = mp.begin(); it != mp.end(); it++) {
        int cnt = it->second;
        if (cnt % t != 0) {
            cout << "-1" << "\n";
            return;
        }
        int r = cnt / t;
        while (r--) {
            ans += it->first;
        }
    }

    int k = s.size() / ans.size() - 1;
    string t = ans;
    while (k--) {
        ans += t;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> t) {
        solve();
    }
    return 0;
}
