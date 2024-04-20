#include <iostream>
#include <climits>
#include <deque>
using namespace std;
int map[74][73];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int check[74][73];
int maximum = 0;
int R, C, K, ans = 0;
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> K;
	for (int i = 1; i <= K; i++)
	{
		int c, d;
		cin >> c >> d;
		int x = 0, y = c;
		while (true)
		{
			if (x == R + 1)break;
			if (!map[x + 1 + 1][y] && !map[x + 1][y - 1] && !map[x + 1][y + 1]) x += 1;
			else
			{
				if (y > 2 && !map[x][y - 2] && !map[x - 1][y - 1] && !map[x + 1][y - 1] && !map[x+2][y-1] && !map[x+1][y-2])
				{
					y -= 1;
					x += 1;
					d = (d + 3) % 4;
				}
				else
				{
					if (y < C - 1 && !map[x][y + 2] && !map[x + 1][y + 1] && !map[x - 1][y + 1] && !map[x+1][y+2] && !map[x+2][y+1])
					{
						y += 1;
						d = (d + 1) % 4;
						x += 1;
					}
					else break;
				}
			}
		}
		if (x <= 3)
		{
			for (int a = 1; a <= R+2; a++)
			{
				for (int b = 1; b <= C; b++)
				{
					map[a][b] = 0;
				}
			}
			continue;
		}
		maximum = 0;
		map[x][y] = i;
		for (int k = 0; k < 4; k++)map[x + dx[k]][y + dy[k]] = i;
		map[x + dx[d]][y + dy[d]] = INT_MAX-i;
		check[x][y] = 1;
		deque<pair<int,int>> dq;
		dq.push_back(make_pair(x, y));
		while (!dq.empty())
		{
			x = dq.front().first;
			y = dq.front().second;
			maximum = max(maximum, x);
			dq.pop_front();
			for (int k = 0; k < 4; k++)
			{
				int nextx = x + dx[k];
				int nexty = y + dy[k];
				if (nextx >= 1 && nextx <= R + 2 && nexty >= 1 && nexty <= C)
				{
					if (check[nextx][nexty] != i)
					{
						if ((map[x][y] > 10000 && map[nextx][nexty]) || (map[x][y] == map[nextx][nexty] || map[nextx][nexty] == INT_MAX - map[x][y]) )
						{
							check[nextx][nexty] = i;
							dq.push_back(make_pair(nextx, nexty));
						}
					}
				}
			}
		}
		ans += maximum-2;
	}
	cout << ans;
	return 0;
}