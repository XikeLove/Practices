#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
const int MAXN = 1000000;
const i64 MOD = 1000000007;

int spf[MAXN + 10];
vector<int> primes;

void build_spf() {
    spf[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            i64 v = i * p;
            if (v > MAXN)
                break;
            spf[v] = p;
            if (i % p == 0)
                break;
        }
    }
}

void factor(int x, unordered_map<int, int> &ump) {
    while (x > 1) {
        int p = spf[x];
        x /= p;
        ump[p]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build_spf();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int k;
        int a, b, c;
        cin >> k >> a >> b >> c;
        i64 ans = 1;
        if (k == 1) {
            //(a^b)*c
            unordered_map<int, int> fa, fc;
            factor(a, fa);
            factor(c, fc);
            //遍历fa
            for (auto &kv : fa) {
                int p = kv.first;
                i64 e = 1LL * b * kv.second + (fc.count(p) ? fc[p] : 0);
                ans = (ans * ((1 + e) % MOD)) % MOD;
                fc.erase(p);
            }
            for (auto &kv : fc) {
                ans = (ans * ((kv.second + 1) % MOD)) % MOD;
            }
        } else {
            //(a*b)^c
            unordered_map<int, int> fa, fb;
            factor(a, fa);
            factor(b, fb);
            for (auto &kv : fa) {
                int p = kv.first;
                i64 e = 1LL * c * (kv.second + (fb.count(p) ? fb[p] : 0));
                ans = (ans * ((1 + e) % MOD)) % MOD;
                fb.erase(p);
            }
            for (auto &kv : fb) {
                i64 e = 1LL * c * kv.second;
                ans = (ans * ((e + 1) % MOD)) % MOD;
            }
        }
        cout << "Case #" << tc << ": " << ans % MOD << "\n";
    }
    return 0;
}