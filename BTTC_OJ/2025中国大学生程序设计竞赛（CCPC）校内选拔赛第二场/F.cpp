#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 2000005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--) {
        int n, m, c;
        cin >> n >> m >> c;

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        vector<int> tin(n + 1), tout(n + 1), depth(n + 1, 0);
        int timer = 0;

        int root = 1;

        struct Node {
            int u, it, state;
        };
        vector<Node> st;
        st.push_back({root, 0, 0});
        vector<int> idx(n + 1, 0);
        vector<int> parent(n + 1, 0);

        while (!st.empty()) {
            Node cur = st.back();
            st.pop_back();
            int u = cur.u;
            if (cur.state == 0) {
                tin[u] = ++timer;
                st.push_back({u, 0, 1});
                for (int i = (int)g[u].size() - 1; i >= 0; --i) {
                    int v = g[u][i];
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, 0, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        auto is_anc = [&](int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; };

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            int ans;
            if (x == c || is_anc(x, c)) {
                ans = 0;
            } else if (is_anc(c, x)) {
                ans = depth[x] - depth[c];
            } else {
                ans = -1;
            }

            if (i)
                cout << ' ';
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
