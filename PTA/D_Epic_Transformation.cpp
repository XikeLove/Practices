#include <bits/stdc++.h>

int minRemainingSize(const std::vector<int>& a) {
    int n =a.size();
    if (n <= 1) return n;
    
    std::unordered_map<int, int> freq;
    int maxCount = 0;
    for (int value : a) {
        maxCount = std::max(maxCount, ++freq[value]);
    }
    
    return std::max(2 * maxCount - n, n % 2);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int>a(n);
        for(int i=0;i<n;i++)std::cin>>a[i];
        std::cout << minRemainingSize(a) << '\n';  
    }
    return 0;
}
