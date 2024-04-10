#include <iostream>
using namespace std;
int ladder[31][11];
int n, m, h, ans = 4;
void dfs(int depth,int last)
{
    if (depth == ans)return;
    bool possible = true;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        for (int j = 1; j <= h; j++)
        {
            if (ladder[j][num - 1])num--;
            else if (ladder[j][num])num++;
        }
        if (num != i)
        {
            possible = false;
            break;
        }
    }
    if (possible)
    {
        ans = min(ans, depth);
        return;
    }
    if (depth == 3)return;
    for (int i = last; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (!ladder[i][j] && !ladder[i][j - 1])
            {
                ladder[i][j] = 1;
                dfs(depth + 1,i);
                ladder[i][j] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    dfs(0,1);
    if (ans == 4)cout << -1;
    else cout << ans;
    return 0;
}