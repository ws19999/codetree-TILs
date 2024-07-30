#include <iostream>
#include <vector>
using namespace std;
int dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,0,-1,-1,-1,0,1,1,1 };
typedef struct chess
{
    int num = 0, dir = 0;
    bool horse = true;
}Chess;
int answer = 0;
void dfs(Chess map[4][4], vector<pair<int, int>> horses, int score)
{
    for (int i = 1; i <= 16; i++)
    {
        int x = horses[i].first;
        int y = horses[i].second;
        if (map[x][y].horse)
        {
            for (int k = 0; k < 8; k++)
            {
                int dir = map[x][y].dir;
                int nextx = x + dx[dir];
                int nexty = y + dy[dir];
                if (nextx >= 0 and nextx < 4 and nexty >= 0 and nexty < 4 and (nextx != horses[0].first or nexty != horses[0].second))
                {
                    int n = map[nextx][nexty].num, d = map[nextx][nexty].dir;
                    bool horse = map[nextx][nexty].horse;
                    horses[n].first = x;
                    horses[n].second = y;
                    horses[i].first = nextx;
                    horses[i].second = nexty;
                    map[nextx][nexty].num = map[x][y].num;
                    map[nextx][nexty].dir = map[x][y].dir;
                    map[nextx][nexty].horse = map[x][y].horse;
                    map[x][y].num = n;
                    map[x][y].dir = d;
                    map[x][y].horse = horse;
                    break;
                }
                else
                {
                    map[x][y].dir++;
                    if (map[x][y].dir == 9)map[x][y].dir = 1;
                }
            }
        }
    }
    int dir = map[horses[0].first][horses[0].second].dir;
    while (true)
    {
        horses[0].first += dx[dir];
        horses[0].second += dy[dir];
        if (horses[0].first < 0 or horses[0].first >= 4 or horses[0].second < 0 or horses[0].second >= 4)break;
        if (!map[horses[0].first][horses[0].second].horse)continue;
        map[horses[0].first][horses[0].second].horse = false;
        dfs(map, horses, score + map[horses[0].first][horses[0].second].num);
        map[horses[0].first][horses[0].second].horse = true;
    }
    answer = max(answer, score);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Chess map[4][4];
    vector<pair<int, int>> horses(17);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j].num >> map[i][j].dir;
            horses[map[i][j].num].first = i;
            horses[map[i][j].num].second = j;
        }
    }
    horses[0].first = 0;
    horses[0].second = 0;
    map[0][0].horse = false;
    dfs(map, horses, map[0][0].num);
    cout << answer;
    return 0;
}