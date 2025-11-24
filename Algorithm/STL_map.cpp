#include <bits/stdc++.h>
using namespace std;

vector<int> v = {3, 1, 4, 1, 5, 6};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 打印初始序列
    for (int num : v) {
        cout << num << " ";
    }
    cout << "\n";

    // 建立大根堆
    make_heap(v.begin(), v.end());

    // 打印堆化后的序列
    for (int num : v) {
        cout << num << " ";
    }
    cout << "\n";

    // 添加元素，向上调整
    v.push_back(2);
    push_heap(v.begin(), v.end());

    // 打印添加元素后的堆
    for (int num : v) {
        cout << num << " ";
    }
    cout << "\n";

    // 弹出堆顶元素(最大值)
    pop_heap(v.begin(), v.end());
    int top_element = v.back();
    v.pop_back();

    // 打印弹出堆顶后的序列
    for (int num : v) {
        cout << num << " ";
    }
    cout << "\n";

    // 判断是否为堆
    bool is_heap_result = is_heap(v.begin(), v.end());
    cout << "Is heap: " << boolalpha << is_heap_result << "\n";

    //堆排序
    while (!v.empty()) {
        pop_heap(v.begin(), v.end());
        int top_element = v.back();
        v.pop_back();
        cout << top_element << " ";
    }
    cout << endl;

    return 0;
}