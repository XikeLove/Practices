#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

vector<int> heap(MAXN);
int n;

//heapInsert 新插入的数，从位置i不断向上维护
void heapInsert(int i) {
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

//heapify 原本数组位置i的数被更改，以数组为i为顶点的子树重新维护
void heapify(int i, int n) {
    int l = 2 * i + 1;
    while (l < n) {
        int best = (l + 1 < n && heap[l + 1] > heap[l]) ? l + 1 : l;
        best = heap[best] > heap[i] ? best : i;
        if (best == i)
            break;
        swap(heap[best], heap[i]);
        i = best;
        l = 2 * i + 1;
    }
}

//从顶到底建堆并进行堆排序
void heapSort1() {
    int size = n;
    for (int i = 0; i < n; i++) {
        heapInsert(i);
    }
    while (size > 1) {
        swap(heap[0], heap[--size]);
        heapify(0, size);
    }
}

//从底到顶建堆并进行堆排序
void heapSort2() {
    int size = n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(i, size);
    }
    while (size > 1) {
        swap(heap[0], heap[--size]);
        heapify(0, size);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }
    heapSort2();
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    return 0;
}