#include <bits/stdc++.h>
using namespace std;

vector<int> getNextArray(const string &s) {
    int n = s.size();
    if (n == 1) {
        return {-1};
    }
    vector<int> next(n);
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int cn = 0;
    while (i < n) {
        if (s[i - 1] == s[cn]) {
            next[i++] = ++cn;
        } else if (cn > 0) {
            cn = next[cn];
        } else {
            next[i++] = 0;
        }
    }
    return next;
}

int kmp(const string &s1, const string &s2) {
    int n = s1.size();
    int m = s2.size();
    int x = 0;
    int y = 0;
    vector<int> next = getNextArray(s2);
    while (x < n && y < m) {
        if (s1[x] == s2[y]) {
            x++;
            y++;
        } else if (y == 0) {
            x++;
        } else {
            y = next[y];
        }
    }
    return (y == m ? x - y : -1);
}

int main() { return 0; }
