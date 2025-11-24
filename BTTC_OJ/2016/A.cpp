#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int dz[205];
        memset(dz, 0, sizeof(dz));
        int ans = 0;
        cin >> n >> m;
        int m1;
        if (m % 2 == 0) {
            m1 = m / 2;
        } else
            m1 = m / 2 + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num;
                cin >> num;
                if (num == 1)
                    dz[i]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (dz[i] >= m1)
                ans++;
        }
        cout << ans << endl;
    }
}