#include <iostream>
#include <deque>
using namespace std;
typedef struct virus
{
    int size, speed, moved=1,dir;
}Virus;
deque <Virus> map[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m, k,ans=0;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m>>k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        Virus v;
        cin >> v.speed >> v.dir >> v.size;
        v.dir--;
        if (v.dir == 1)v.dir = 2;
        else if (v.dir == 2)v.dir = 1;
        if (v.dir == 0 || v.dir == 2)v.speed = v.speed % ((n - 1) * 2);
        else v.speed = v.speed % ((m - 1) * 2);
        map[x][y].push_back(v);
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!map[i][j].empty())
            {
                ans += map[i][j].front().size;
                map[i][j].pop_front();
                break;
            }
        }
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= m; b++)
            {
                if (!map[a][b].empty())
                {
                    if (map[a][b].front().moved == j)
                    {
                        Virus v = map[a][b].front();
                        
                        map[a][b].pop_front();
                        int x = a, y = b;
                        for (int c = 0; c < v.speed; c++)
                        {
                            if (x + dx[v.dir] == 0 || x + dx[v.dir] == n+1 || y + dy[v.dir] == 0 || y + dy[v.dir] == m+1)v.dir = (v.dir + 2) % 4;
                            x += dx[v.dir];
                            y += dy[v.dir];
                        }
                        v.moved++;
                        if (map[x][y].size() == 2)
                        {
                            if (map[x][y].back().size < v.size)
                            {
                                map[x][y].pop_back();
                                map[x][y].push_back(v);
                            }
                        }
                        else if (map[x][y].size() == 1)
                        {
                            if (map[x][y].front().size < v.size && map[x][y].front().moved>j)
                            {
                                map[x][y].pop_back();
                                map[x][y].push_back(v);
                            }
                            else if (map[x][y].front().moved == j)map[x][y].push_back(v);
                        }
                        else map[x][y].push_back(v);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}