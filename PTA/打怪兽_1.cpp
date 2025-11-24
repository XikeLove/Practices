#include<bits/stdc++.h>
using ld = long double;

ld n, d, h;

struct State {
    ld hp;
    ld mp;
    bool cheat;
    bool mianyi;
    ld suffer;
};

ld max(ld a, ld b) {
    if (a >= b)return a;
    else return b;
}

ld min(ld a, ld b) {
    if (a >= b)return b;
    else return a;
}

ld ans = -1.0;

void dfs(int index, bool atkbuff, State state) {
    if (index == n || (state.hp <= 0 && state.cheat && !state.mianyi)) {
        ans = max(ans, state.suffer * 1.2L);
        return;
    }
    //枚举增益
    if (!atkbuff) {
        dfs(index, true, state);
    }
    //枚举暴击
    for (int i = 0; i <= 1; i++) {
        State cur = state;
        ld k = (atkbuff ? 1.2L : 1.0L) * (i ? 2.0L : 1.0L);
        ld damage = k * d;
        cur.suffer += damage;
        //  不免疫伤害
        if (!cur.mianyi) {
            cur.mp += 10;
            cur.hp -= damage;
            //看hp是否小于0？
            if (cur.hp <= 0) {
                //技能可以恢复
                // 技能可以恢复
                if (!cur.cheat) {
                    long double cover_hp = 1.0L + h * (cur.mp / 100.0L);
                    cur.cheat = true;
                    if (cur.mp >= 100.0L-1e-12L) cur.mianyi = true;
                    cur.hp = cover_hp;
                    if (cur.hp > h) cur.hp =h;
                    cur.mp = 0.0L;
                    dfs(index + 1, atkbuff, cur);
                } else {
                    ans = max(ans, cur.suffer * 1.2L);
                    continue;
                }
            } else {
                dfs(index + 1, atkbuff, cur);
            }
        }
        //免疫伤害
        else dfs(index + 1, atkbuff, cur);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> d >> h;

    State inital = {1.0 * h, 0, false, false, 0};

    dfs(0, false, inital);
    std::cout << std::fixed << std::setprecision(2) << ans << "\n";

    return 0;
}
