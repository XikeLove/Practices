#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x;
    int y;
};

int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> g(n);
        for (int i = 0; i < n; i++)
            cin >> g[i];
        int N = n;
        auto inG = [&](int x, int y) { return 0 <= x && x <= N && 0 <= y && y <= N; };
        vector<vector<char>> badG(N + 1, vector<char>(N + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'S') {
                    badG[i][j] = 1;
                    badG[i + 1][j] = 1;
                    badG[i][j + 1] = 1;
                    badG[i + 1][j + 1] = 1;
                }
            }
        }
        auto rot = [&](int x, int y) -> pair<int, int> { return {N - x, N - y}; };
        auto okEdge = [&](int x1, int y1, int x2, int y2) {
            if (!inG(x1, y1) || !inG(x2, y2))
                return false;
            if (badG[x1][y1] || badG[x2][y2])
                return false;
            return true;
        };
        auto isBoundary = [&](int x, int y) { return (x == 0 || x == n || y == 0 || y == n); };
        int cx = n / 2;
        int cy = n / 2;
        if (badG[cx][cy]) {
            cout << "No\n";
            continue;
        }
        bool ok = false;
        vector<vector<char>> vis(N + 1, vector<char>(N + 1, 0));
        queue<Node> q;
        vis[cx][cy] = 1;
        q.push({cx, cy});
        while (!q.empty()) {
            Node cur = q.front();
            q.pop();
            int x = cur.x, y = cur.y;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (!inG(nx, ny))
                    continue;
                if (vis[nx][ny])
                    continue;
                if (!okEdge(x, y, nx, ny))
                    continue;
                auto r1 = rot(x, y);
                auto r2 = rot(nx, ny);
                if (!okEdge(r1.first, r1.second, r2.first, r2.second))
                    continue;
                if (vis[nx][ny] || vis[r2.first][r2.second])
                    continue;
                vis[nx][ny] = 1;
                vis[r2.first][r2.second] = 1;
                if (isBoundary(nx, ny)) {
                    ok = true;
                    break;
                }
                q.push({nx, ny});
            }
            if (ok)
                break;
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}