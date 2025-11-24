#include <bits/stdc++.h>
using namespace std;

struct State {
    long double hp;
    long double mp;
    bool cheatUsed;
    bool immune;
    long double dealt;
};

int n;
long double d, h;
long double best = 0;

void dfs(int idx, bool buffTriggered,  State st) {
    // 所有炮弹打完，或怪兽在非免疫状态下第二次阵亡
    if (idx == n || (!st.immune && st.hp <= 0 && st.cheatUsed)) {
        best = max(best, st.dealt * 1.2L);
        return;
    }

    // 若增益还未触发，可在当前回合立即触发一次
    if (!buffTriggered) {
        dfs(idx, true,  st);  // 触发后当前这一发也享受增益
    }
    for (int crit = 0; crit < 2; ++crit) {
        State cur = st;
        long double multiplier = (buffTriggered ? 1.2L : 1.0L) * (crit ? 2.0L : 1.0L);
        long double damage = d * multiplier;
        cur.dealt += damage;

        if (!cur.immune) {
            cur.mp += 10.0L;
            cur.hp -= damage;

            if (cur.hp <= 0) {
                if (!cur.cheatUsed) {
                    cur.cheatUsed = true;
                    long double mpBefore = cur.mp;
                    cur.hp = 1.0L + h * (mpBefore / 100.0L);
                    if (cur.hp > h) cur.hp = h;
                    if (mpBefore >= 100.0L - 1e-12L) cur.immune = true;
                    cur.mp = 0.0L;
                } else {
                    best = max(best, cur.dealt * 1.2L);
                    continue;
                }
            }
        }

        dfs(idx + 1, buffTriggered,  cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> d >> h)) return 0;

    State initial{h, 0.0L, false, false, 0.0L};
    dfs(0, false,  initial);

    cout << fixed << setprecision(2) << (double)best << '\n';
    return 0;
}
