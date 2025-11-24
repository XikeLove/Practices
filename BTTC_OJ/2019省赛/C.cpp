#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    double math;
    double english;
    double potlic;
    double profess;
    double total;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    double pass_m = 150 * 0.6;
    double pass_e = 100 * 0.6;
    double pass_p = 100 * 0.6;
    double pass_pro = 150 * 0.6;
    while (T--) {
        vector<Student> students;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string name;
            double M, E, P, Z;
            cin >> name >> M >> E >> P >> Z;
            if (M >= pass_m && E >= pass_e && P >= pass_p && Z >= pass_pro) {
                students.push_back({name, M, E, P, Z, M + E + P + Z});
            }
        }
        sort(students.begin(), students.end(), [](const Student A, const Student B) {
            if (A.name != B.name) {
                return A.total > B.total;
            } else {
                return A.name < B.name;
            }
        });
        for (auto x : students) {
            cout << x.name << " " << x.total << "\n";
        }
    }
    return 0;
}