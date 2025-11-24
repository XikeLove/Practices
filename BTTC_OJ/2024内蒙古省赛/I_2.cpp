#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

//所有炮弹效果:普攻炮弹，强化炮弹，暴击炮弹，强化暴击炮弹
int effect_pre[4] = {1, 2, 3, 4};

//强化后的炮弹效果: 强化炮弹，强化暴击炮弹
int effect_aft[2] = {2, 4};

//倍率1
double beilv1 = [1, 1.2, 2, 2.4];

//倍率2
double beilv2 = [1.2, 2.4];

struct element {
    char ch;
    double val;
    double magic;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    double hp;
    cin >> n >> d >> hp;
    string ans = "";
    queue<element> q;
    // q.push("0");
    for (int i = 0; i < 4; i++) {
        q.push({'0' + effect_pre[i], d * beilv1[i], 0});
    }

    for (int i = 2; i <= n; i++) {
        queue<element> temp = q;
        int temp_size = temp.size();
        while (!temp.empty()) {
            element head = q.front();
            q.pop();

            //如果强化攻击已经被打出来只会有强化炮弹和强化暴击炮弹
            if (head == '2' || head == '4') {
                for (int i = 0; i < 2; i++) {
                    q.push({'0' + effect_aft[i],
                            head.val + d * beilv2[i],
                            ((head.magic + 10) > 100 ? 100 : head.magic + 10)});
                }
            } else {
                for (int i = 0; i < 4; i++) {
                    q.push({'0' + effect_pre[i], head.val + d * beilv1[i], head.magic + 10});
                }
            }
            double atk = head.val;
            if (atk >= h) {
                hp += head.magic;
            }
        }
        while (temp_size--) {
            q.pop();
        }
    }
    while(!q.empty(){
    	
    }

    return 0
}