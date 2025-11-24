#include <bits/stdc++.h>
using namespace std;

int n, ans;
int sum;

struct Tm {
    int t;
    int a;
    bool wc;
    double zb;
};

bool cmp(Tm m1, Tm m2) { return m1.zb > m2.zb; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        Tm tms[n];
        for (int i = 0; i < n; i++) {
            cin >> tms[i].t;
            tms[i].wc = false;
        }
        for (int i = 0; i < n; i++) {
            cin >> tms[i].a;
            sum += tms[i].a;
            tms[i].zb = (double)tms[i].a / tms[i].t;
        }
        sort(tms, tms + n, cmp);
        for (int i = 0; i < n; i++) {
            ans += sum * tms[i].t;
            sum -= tms[i].a;
        }
        cout << ans << endl;
    }
}