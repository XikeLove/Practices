// Problem: B - Perfect
// Contest: AtCoder - AtCoder Beginner Contest 424
// URL: https://atcoder.jp/contests/abc424/tasks/abc424_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<bool>> solved_status(N + 1, std::vector<bool>(M + 1, false));

    std::vector<int> solved_count(N + 1, 0);

    std::vector<int> finishers;

    std::vector<bool> has_finished(N + 1, false);

    for (int i = 0; i < K; ++i) {
        int person, problem;
        std::cin >> person >> problem;

        if (!solved_status[person][problem]) {
            solved_status[person][problem] = true;

            solved_count[person]++;

            if (solved_count[person] == M && !has_finished[person]) {
                finishers.push_back(person);

                has_finished[person] = true;
            }
        }
    }
    for (size_t i = 0; i < finishers.size(); ++i) {
        std::cout << finishers[i] << (i == finishers.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}