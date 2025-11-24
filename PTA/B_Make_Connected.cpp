#include <bits/stdc++.h>

std::vector<std::string> grip;
int n;
int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool threeContious()
{
    // 横三
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 2 < n; j++)
        {
            if (grip[i][j] == '#' && grip[i][j + 1] == '#' && grip[i][j + 2] == '#')
            {
                return false;
            }
        }
    }
    // 竖三
    for (int i = 0; i + 2 < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grip[i][j] == '#' && grip[i + 1][j] == '#' && grip[i + 2][j] == '#')
            {
                return false;
            }
        }
    }
    return true;
}

bool TwoConnect()
{
    int cnt = 0;
    std::vector<std::vector<int>> used(n, std::vector<int>(n));
    std::vector<int> all_degree;

    auto inEdge = [](int x, int y)
    {
        if (x >= 0 && x < n && y >= 0 && y < n)
            return true;
        else
            return false;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grip[i][j] == '#' && !used[i][j])
            {
                cnt++;
                std::queue<std::pair<int, int>> q;
                q.push({i, j});
                used[i][j] = true;
                while (!q.empty())
                {
                    int degree = 0;
                    auto [cx, cy] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int newx = cx + d[i][0];
                        int newy = cy + d[i][1];
                        if (!inEdge(newx, newy) || grip[newx][newy] != '#')
                            continue;
                        degree++;
                        if (!used[newx][newy])
                        {
                            q.push({newx, newy});
                            used[newx][newy] = true;
                        }
                    }
                    all_degree.push_back(degree);
                }
            }
        }
    }
    if(std::all_of(all_degree.begin(),all_degree.end(),[&cnt](int d)->bool {return d==2&&cnt>1;})){
        return false;
    }else  return true;
}

void solve()
{
    std::cin >> n;
    grip.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> grip[i];
    }
    if (n == 1)
    {
        std::cout << "YES\n";
        return;
    }
    if (!threeContious() ||!TwoConnect())
    {
        std::cout << "NO\n";
        return;
    }
    else std::cout<<"----\n";
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
