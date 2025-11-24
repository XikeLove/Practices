#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Peo {
    i64 HP;
    i64 DPS;
    double rate;
};

i64 n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        vector<Peo> peos;
        i64 total_DPS = 0;
        for (int i = 0; i < n; i++) {
            i64 hp;
            i64 dps;
            cin >> hp >> dps;
            total_DPS += dps;
            double rate = 1.0 * dps / hp;
            peos.push_back({hp, dps, rate});
        }
        sort(peos.begin(), peos.end(), [](const Peo &A, const Peo &B) { return A.rate > B.rate; });
        i64 total_HP = 0;
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            ans += peos[i].DPS * (total_HP + peos[i].HP);
            //cout << "---" << total_HP << endl;
            total_HP += peos[i].HP;
        }
        cout << ans << "\n";
    }

    return 0;
}