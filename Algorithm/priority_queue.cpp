#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int age;
};

struct CompareAge {
    bool operator()(const Person &A, const Person &B) { return A.age > B.age; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //默认构造是大根堆
    priority_queue<int> pq1;

    //从已有数据构造
    vector<int> vec = {3, 1, 4, 1, 5};
    priority_queue<int> pq2(vec.begin(), vec.end());

    //小根堆 或者自己定义比较规则
    priority_queue<int, vector<int>, greater<int>> pq3;

    //大根堆
    priority_queue<int> max_pq;

    max_pq.push(3);
    max_pq.push(1);
    max_pq.push(4);
    max_pq.push(1);
    max_pq.push(5);
    max_pq.push(2);
    max_pq.push(7);

    cout << "Max heap:";
    while (!max_pq.empty()) {
        cout << max_pq.top() << " ";
        max_pq.pop();
    }

    auto cmp = [](const Person &a, const Person &b) { return a.age < b.age; };
    priority_queue<Person, Person, decltype(cmp)> age_pq(cmp);

    cout << endl;

    return 0;
}