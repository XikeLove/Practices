#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        while (n % 2 == 0) {
            bool valid = true;
            int half = n >> 1;
            for (int i = 0; i < half; i++) {
                if (s[i] != s[n - 1 - i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                n = half;
            } else {
                break;
            }
        }
        cout << n << "\n";
    }
    return 0;
}