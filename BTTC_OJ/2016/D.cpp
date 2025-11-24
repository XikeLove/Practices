#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin >> s) {
        int n = s.size();
        vector<int> pre(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (s[i - 1] == 'X' ? 2 : -1);
        }
        vector<int> stk;
        for (int i = 0; i <= n - 1; i++) {
            if (stk.empty() || pre[i] < pre[stk.back()]) {
                stk.push_back(i);
            }
        }
        int ans = 0;
        for (int r = n; r >= 1; r--) {
            while (!stk.empty() && pre[r] >= pre[stk.back()]) {
                ans = max(ans, r - stk.back());
                stk.pop_back();
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
