#include <bits/stdc++.h>
using namespace std;

static const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int n;
        cin >> n;

        vector<int> low(M + 1, 1), high(M + 1, N);
        int Amax = 0;
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            low[a] = b + 1;
            high[a] = N - c;
            Amax = max(Amax, a);
        }

        if (n == 0) {
            cout << 0 << "\n";
            continue;
        }

        bool bad = false;
        for (int col = 1; col <= Amax; ++col) {
            if (low[col] > high[col]) {
                bad = true;
                break;
            }
        }
        if (bad) {
            cout << -1 << "\n";
            continue;
        }

        vector<vector<int>> dist(Amax + 1, vector<int>(N + 1, INF));
        deque<pair<int, int>> dq;

        for (int r = low[1]; r <= high[1]; ++r) {
            dist[1][r] = 0;
            dq.push_back(make_pair(1, r));
        }

        int ans = -1;

        while (!dq.empty()) {
            pair<int, int> cur = dq.front();
            dq.pop_front();
            int c = cur.first;
            int r = cur.second;

            if (c == Amax) {
                ans = dist[c][r];
                break;
            }

            int nc = c + 1;
            if (nc > Amax)
                continue;

            if (r > 1) {
                int nr = r - 1;
                if (low[nc] <= nr && nr <= high[nc] && dist[nc][nr] > dist[c][r]) {
                    dist[nc][nr] = dist[c][r];
                    dq.push_front(make_pair(nc, nr));
                }
            }

            if (r < N) {
                int nr = r + 1;
                if (low[nc] <= nr && nr <= high[nc] && dist[nc][nr] > dist[c][r] + 1) {
                    dist[nc][nr] = dist[c][r] + 1;
                    dq.push_back(make_pair(nc, nr));
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
