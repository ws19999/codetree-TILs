#include <iostream>
#include <deque>
using namespace std;
int map[5][5];
int table[300];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool check[5][5] = { false };
bool find = false;
int tresures = 0;
void dfs(int x, int y, int num)
{
    map[x][y] = 0;
    for (int k = 0; k < 4; k++)
    {
        int nextx = x + dx[k];
        int nexty = y + dy[k];
        if (nextx >= 0 && nextx < 5 && nexty >= 0 && nexty < 5)
        {
            if (map[nextx][nexty] == num)
            {
                dfs(nextx, nexty, num);
            }
        }
    }
}
int main() {
    int K, M;
    cin >> K >> M;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < M; i++)cin >> table[i];
    int tresurepos = 0;
    for (int tc = 1; tc <= K; tc++)
    {
        int angle = 4, turnx = 5, turny = 5, price = 0, turnprice = 0;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    int a = map[i - 1][j];
                    int b = map[i - 1][j + 1];
                    map[i - 1][j + 1] = map[i - 1][j - 1];
                    map[i - 1][j] = map[i][j - 1];
                    map[i - 1][j - 1] = map[i + 1][j - 1];
                    map[i][j - 1] = map[i + 1][j];
                    map[i + 1][j - 1] = map[i + 1][j + 1];
                    map[i + 1][j] = map[i][j + 1];
                    map[i + 1][j + 1] = b;
                    map[i][j + 1] = a;
                    int tempprice = 0;
                    
                    for (int l = 0; l < 5; l++)
                    {
                        for (int m = 0; m < 5; m++)
                        {
                            check[l][m] = false;
                        }
                    }
                    for (int l = 0; l < 5; l++)
                    {
                        for (int m = 0; m < 5; m++)
                        {
                            if (!check[l][m])
                            {
                                check[l][m] = true;
                                int cnt = 0;
                                deque<pair<int, int>> dq;
                                dq.push_back(make_pair(l, m));
                                while (!dq.empty())
                                {
                                    int x = dq.front().first;
                                    int y = dq.front().second;
                                    cnt++;
                                    dq.pop_front();
                                    for (int n = 0; n < 4; n++)
                                    {
                                        int nextx = x + dx[n];
                                        int nexty = y + dy[n];
                                        if (nextx >= 0 && nextx < 5 && nexty >= 0 && nexty < 5)
                                        {
                                            if (!check[nextx][nexty] && map[nextx][nexty] == map[x][y])
                                            {
                                                check[nextx][nexty] = true;
                                                dq.push_back(make_pair(nextx, nexty));
                                            }
                                        }
                                    }
                                }
                                if (cnt >= 3)tempprice += cnt;
                            }
                        }
                    }
                    
                    if (tempprice > price)
                    {
                        price = tempprice;
                        angle = k;
                        turnx = i;
                        turny = j;
                    }
                    else if (tempprice == price)
                    {
                        if (k < angle)
                        {
                            price = tempprice;
                            angle = k;
                            turnx = i;
                            turny = j;
                        }
                        else if (k == angle)
                        {
                            if (i < turnx)
                            {
                                price = tempprice;
                                angle = k;
                                turnx = i;
                                turny = j;
                            }
                            else if (turnx == i)
                            {
                                if (j < turny)
                                {
                                    price = tempprice;
                                    angle = k;
                                    turnx = i;
                                    turny = j;
                                }
                            }
                        }
                    }
                }
                int a = map[i - 1][j];
                int b = map[i - 1][j + 1];
                map[i - 1][j + 1] = map[i - 1][j - 1];
                map[i - 1][j] = map[i][j - 1];
                map[i - 1][j - 1] = map[i + 1][j - 1];
                map[i][j - 1] = map[i + 1][j];
                map[i + 1][j - 1] = map[i + 1][j + 1];
                map[i + 1][j] = map[i][j + 1];
                map[i + 1][j + 1] = b;
                map[i][j + 1] = a;
            }
        }
        if (price == 0)break;
        int i = turnx;
        int j = turny;
        for (int k = 0; k < angle; k++)
        {
            int a = map[i - 1][j];
            int b = map[i - 1][j + 1];
            map[i - 1][j + 1] = map[i - 1][j - 1];
            map[i - 1][j] = map[i][j - 1];
            map[i - 1][j - 1] = map[i + 1][j - 1];
            map[i][j - 1] = map[i + 1][j];
            map[i + 1][j - 1] = map[i + 1][j + 1];
            map[i + 1][j] = map[i][j + 1];
            map[i + 1][j + 1] = b;
            map[i][j + 1] = a;
        }
        while (true)
        {
            int tempprice = 0;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    check[i][j] = false;
                }
            }
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (!check[i][j])
                    {
                        check[i][j] = true;
                        int cnt = 0;
                        deque<pair<int, int>> dq;
                        dq.push_back(make_pair(i, j));
                        while (!dq.empty())
                        {
                            int x = dq.front().first;
                            int y = dq.front().second;
                            cnt++;
                            dq.pop_front();
                            for (int n = 0; n < 4; n++)
                            {
                                int nextx = x + dx[n];
                                int nexty = y + dy[n];
                                if (nextx >= 0 && nextx < 5 && nexty >= 0 && nexty < 5)
                                {
                                    if (!check[nextx][nexty] && map[nextx][nexty] == map[x][y])
                                    {
                                        check[nextx][nexty] = true;
                                        dq.push_back(make_pair(nextx, nexty));
                                    }
                                }
                            }
                        }
                        if (cnt >= 3)
                        {
                            tempprice += cnt;
                            dfs(i, j, map[i][j]);
                        }
                    }
                }
            }
            if (!tempprice)break;
            turnprice += tempprice;
            for (int j = 0; j < 5; j++)
            {
                for (int i = 4; i >= 0; i--)
                {
                    if (!map[i][j])
                    {
                        map[i][j] = table[tresurepos++];
                    }
                }
            }
        }
        cout << turnprice << " ";
    }
    return 0;
}