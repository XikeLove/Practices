#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<string, string> mp_type;
    unordered_map<string, string> mp_input;
    vector<string> names;
    string s;
    int statue = 1;

    while (getline(cin, s)) {
        if (s.size() == 4 && s == "type") {
            statue = 1;
            continue;
        } else if (s.size() == 5 && s == "input") {
            statue = 2;
            continue;
        } else if (s.size() == 3 && s == "end") {
            statue = 3;
            break;
        } else {
            int p = s.find(" ");
            string a = s.substr(0, p);
            string b = s.substr(p + 1);
            if (statue == 1) {
                mp_type[a] = b;
                mp_input[b] = "null";
                names.push_back(a);
            } else {
                mp_input[a] = b;
            }
        }
    }
    for (auto na : names) {
        cout << na << ":" << mp_input[mp_type[na]] << "\n";
    }

    return 0;
}
