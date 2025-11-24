#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x, y;
        cin >> x >> y;
        int max_x = x;
        pair<int, int> max_x_pii = {x, y};
        int max_y = y;
        pair<int, int> max_y_pii = {x, y};
        vector<pair<int, int>> pii;
        for (int i = 2; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            if (x <= max_x && y <= max_y)
                continue;
            if (x > max_y_pii.first || y > max_x_pii.second) {
                pii.push_back({x, y});
            }
            if (x > max_x) {
                x = max_x;
                max_x_pii = {x, y};
            }
            if (y > max_y) {
                y = max_y;
                max_y_pii = {x, y};
            }
        }
        sort(pii.begin(), pii.end(), [](const pair<int, int> A, const pair<int, int> B) { return A.first < B.first; });
        for (auto x : pii) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}