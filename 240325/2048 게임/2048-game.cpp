#include <iostream>
using namespace std;
int n, ans;
void dfs(int num, int map[20][20])
{
    int t[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = map[i][j];
        }
    }
    for (int k = 0; k < 4; k++)
    {
        if (k == 0)
        {
            for (int i = 0; i < n; i++)
            {
                int right = n - 1;
                for (int left = n - 2; left >= 0; left--)
                {
                    if (map[i][left] == 0)continue;
                    if (map[i][right] == 0)
                    {
                        int temp = map[i][left];
                        map[i][left] = 0;
                        map[i][right] = temp;
                    }
                    else if (map[i][left] == map[i][right])
                    {
                        map[i][right--] *= 2;
                        ans = max(ans, map[i][left] * 2);
                        map[i][left] = 0;
                    }
                    else
                    {
                        int temp = map[i][left];
                        map[i][left] = 0;
                        map[i][--right] = temp;
                    }
                }
            }
        }
        else if (k == 1)
        {
            for (int j = 0; j < n; j++)
            {
                int down = n - 1;
                for (int up = n - 2; up >= 0; up--)
                {
                    if (map[up][j] == 0)continue;
                    if (map[down][j] == 0)
                    {
                        int temp = map[up][j];
                        map[up][j] = 0;
                        map[down][j] = temp;
                    }
                    else if (map[up][j] == map[down][j])
                    {
                        map[down--][j] *= 2;
                        ans = max(ans, map[up][j] * 2);
                        map[up][j] = 0;
                    }
                    else
                    {
                        int temp = map[up][j];
                        map[up][j] = 0;
                        map[--down][j] = temp;
                    }
                }
            }
        }
        else if (k == 2)
        {
            for (int i = 0; i < n; i++)
            {
                int left = 0;
                for (int right = 1; right < n; right++)
                {
                    if (map[i][right] == 0)continue;
                    if (map[i][left] == 0)
                    {
                        int temp = map[i][right];
                        map[i][right] = 0;
                        map[i][left] = temp;
                    }
                    else if (map[i][right] == map[i][left])
                    {
                        map[i][left++] *= 2;
                        ans = max(ans, map[i][right] * 2);
                        map[i][right] = 0;
                    }
                    else
                    {
                        int temp = map[i][right];
                        map[i][right] = 0;
                        map[i][++left] = temp;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                int up = 0;
                for (int down = 1; down < n; down++)
                {
                    if (map[down][j] == 0)continue;
                    if (map[up][j] == 0)
                    {
                        int temp = map[down][j];
                        map[down][j] = 0;
                        map[up][j] = temp;
                    }
                    else if (map[down][j] == map[up][j])
                    {
                        map[up++][j] *= 2;
                        ans = max(ans, map[down][j] * 2);
                        map[down][j] = 0;
                    }
                    else
                    {
                        int temp = map[down][j];
                        map[down][j] = 0;
                        map[++up][j] = temp;
                    }
                }
            }
        }
        if (num > 1)dfs(num - 1, map);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i][j] = t[i][j];
            }
        }
    }
}
int main() {
    cin >> n;
    int map[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            ans = max(ans,map[i][j]);
        }
    }
    dfs(5, map);
    cout << ans;
    return 0;
}