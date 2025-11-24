#include <bits/stdc++.h>
using namespace std;

struct Pm {
    int vi;
    int wi;
    int sum; //已经走过的距离
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;

        Pm pms[n] = {0};

        for (int i = 0; i < n; i++) {
            int tag, tag1;
            cin >> tag >> tag1;
            pms[i].vi = tag;
            pms[i].wi = tag1;
            pms[i].sum = 0;
        }
    }

    return 0;
}