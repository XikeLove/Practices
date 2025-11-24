#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 2; i < n; i+=2)
    {
        if (arr[i-1] != arr[i])
        {
            std::cout<<"NO"<<"\n";
            return ;
        }
    }
    std::cout<<"YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}