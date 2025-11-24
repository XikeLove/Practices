#include <iostream>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

vector<int> adj[1001];
int k[1001];
int parent[1001];
bool visited[1001];

void dfs(int u, int p) {
    visited[u] = true;
    parent[u] = p;

    for (int v : adj[u]) {
        if (v != p && !visited[v]) {
            dfs(v, u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, E;
    while (cin >> N >> S >> E) {
        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
        }

        memset(visited, 0, sizeof(visited));
        memset(parent, 0, sizeof(parent));

        for (int i = 1; i <= N; ++i) {
            cin >> k[i];
        }

        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(S, 0);

        if (!visited[E]) {
            cout << -1 << endl;
        } else {
            long long total_spots = 0;
            int current_node = E;

            while (current_node != 0) {
                total_spots += k[current_node];
                current_node = parent[current_node];
            }

            cout << total_spots << endl;
        }
    }

    return 0;
}