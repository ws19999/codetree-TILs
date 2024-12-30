#include <iostream>
#include <deque>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    int dir = 0;
    int top = 1;
    int east = 3;
    int west = 4;
    int bottom = 6;
    int north = 5;
    int south = 2;
    int map[21][21];
    int n, k;
    int x = 1;
    int y = 1;
    int ans = 0;
    int temp;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    while (k--)
    {
        if (x + dx[dir]<1 || x + dx[dir]>n || y + dy[dir]<1 || y + dy[dir]>n) dir = (dir + 2) % 4;
        x += dx[dir];
        y += dy[dir];
        temp = top;
        if (dir == 0)
        {
            top = west;
            west = bottom;
            bottom = east;
            east = temp;
        }
        else if (dir == 1)
        {
            top = north;
            north = bottom;
            bottom = south;
            south = temp;
        }
        else if (dir == 2)
        {
            top = east;
            east = bottom;
            bottom = west;
            west = temp;
        }
        else if (dir == 3)
        {
            top = south;
            south = bottom;
            bottom = north;
            north = temp;
        }
        if (bottom > map[x][y])dir = (dir + 1) % 4;
        else if (bottom < map[x][y])dir = (dir + 3) % 4;
        int check[21][21] = { 0 };
        int cnt = 0;
        deque <pair<int,int>> dq;
        dq.push_back(make_pair(x, y));
        cnt++;
        check[x][y] = 1;
        while (!dq.empty())
        {
            int i = dq.front().first;
            int j = dq.front().second;
            dq.pop_front();
            for (int k = 0; k < 4; k++)
            {
                if (i + dx[k]<1 || i + dx[k]>n || j + dy[k]<1 || j + dy[k]>n)continue;
                if (map[i + dx[k]][j + dy[k]] != map[x][y])continue;
                if (check[i + dx[k]][j + dy[k]])continue;
                check[i + dx[k]][j + dy[k]] = 1;
                dq.push_back(make_pair(i + dx[k], j + dy[k]));
                cnt++;
            }
        }
        ans += cnt * map[x][y];
    }
    cout << ans;
    return 0;
}