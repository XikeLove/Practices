// #include <bits/stdc++.h>
// using namespace std;
// const int INF = 0x3f3f3f3f;
//
// int ans = -INF;
// int n;
// vector<int> nums;
// vector<int> box;
//
// void dfs(int idx, int temp) {
// if (idx >= n) {
// if (temp % 2 == 0 && box.size() != 0) {
// ans = max(ans, temp);
// }
// return;
// }
// dfs(idx + 1, temp);
// box.push_back(nums[idx]);
// dfs(idx + 1, temp + nums[idx]);
// box.pop_back();
// }
//
// int main() {
// ios::sync_with_stdio(false);
// cin.tie(0);
// cin >> n;
// if (n == 1) {
// int x;
// cin >> x;
// if (x % 2 == 1) {
// cout << "It's just that there's nothing I can do about it." << "\n";
// return 0;
// }
// }
// for (int i = 0; i < n; i++) {
// int x;
// cin >> x;
// nums.push_back(x);
// }
// dfs(0, 0);
// if (ans != -INF)
// cout << ans << "\n";
// else
// cout << "It's just that there's nothing I can do about it." << "\n";
// return 0;
// }
//
