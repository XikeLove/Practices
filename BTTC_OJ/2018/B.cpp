#include <bits/stdc++.h>
using namespace std;

static const int NEG_INF = -1000000000;

// 需要的饮料数：ceil(need/30)，need<=0 返回 0
inline int need_drinks(int need) {
    if (need <= 0)
        return 0;
    return (need + 29) / 30;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> dmg(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> dmg[i];

        vector<vector<int>> dp(a + 1, vector<int>(b + 1, NEG_INF));
        dp[0][0] = 100;

        int answer = -1;

        for (int i = 1; i <= n; ++i) {
            vector<vector<int>> ndp(a + 1, vector<int>(b + 1, NEG_INF));
            bool any = false;

            for (int ua = 0; ua <= a; ++ua) {
                for (int ub = 0; ub <= b; ++ub) {
                    int hp = dp[ua][ub];
                    if (hp <= 0)
                        continue;

                    {
                        int d0 = need_drinks(dmg[i] + 1 - hp);
                        if (ub + d0 <= b) {
                            int hp_before = min(100, hp + 30 * d0);
                            int hp_after = hp_before - dmg[i];
                            if (hp_after > 0 && hp_after > ndp[ua][ub + d0]) {
                                ndp[ua][ub + d0] = hp_after;
                                any = true;
                            }
                        }
                    }

                    if (hp < 70 && ua < a) {
                        int hp1 = 70;
                        int d1 = need_drinks(dmg[i] + 1 - hp1);
                        if (ub + d1 <= b) {
                            int hp_before = min(100, hp1 + 30 * d1);
                            int hp_after = hp_before - dmg[i];
                            if (hp_after > 0 && hp_after > ndp[ua + 1][ub + d1]) {
                                ndp[ua + 1][ub + d1] = hp_after;
                                any = true;
                            }
                        }
                    }
                }
            }

            if (!any) {
                answer = i - 1;
                break;
            }
            dp.swap(ndp);
        }

        if (answer == -1)
            answer = n;
        cout << answer << '\n';
    }
    return 0;
}
