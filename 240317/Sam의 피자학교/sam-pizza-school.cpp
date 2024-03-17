#include <iostream>
using namespace std;
int bowl[100][100];
int nextbowl[100][100];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,K, Min = 10000, Max = 0, ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> bowl[N - 1][i];
		Min = min(Min, bowl[N - 1][i]);
		Max = max(Max, bowl[N - 1][i]);
	}
	while (true)
	{
		if (Max - Min <= K)break;
		//그림 2
		for (int i = 0; i < N; i++)
		{
			if (bowl[N - 1][i] == Min)bowl[N - 1][i]++;
		}
		//그림 3
		bowl[N - 2][1] = bowl[N - 1][0];
		bowl[N - 1][0] = 0;

		int left = 1;
		int bottom = N - 1;
		int high = 2;
		int cnt = 1;
		if (bottom - cnt - high >= 0)
		{
			while (true)
			{
				for (int h = N - 1 - cnt; h < N - 1; h++)
				{
					for (int w = left + cnt - 1 + high; w >= left + cnt; w--)
					{
						int H = N + left + cnt - w - 1;
						int W = h + cnt - N + 1 + left;
						bowl[h][w] = bowl[H][W];
						bowl[H][W] = 0;
					}
				}
				bottom -= cnt;
				left += cnt;
				int temp = cnt;
				cnt = high;
				high = temp + 1;
				if (bottom - cnt - high < 0)break;
			}
        }
		//그림 7
		int i = 0;
		for (int w = left; w < left + cnt; w++)
		{
			for (int h = N - 1; h > N - 1 - high; h--)
			{
				for (int k = 2; k < 4; k++)
				{
					int nextx = h + dx[k];
					int nexty = w + dy[k];
					if (nextx<0 || nextx>=N || nexty<0 || nexty>=N)continue;
					if (!bowl[nextx][nexty])continue;
					if (bowl[h][w] > bowl[nextx][nexty])
					{
						nextbowl[h][w] -= (bowl[h][w] - bowl[nextx][nexty]) / 5;
						nextbowl[nextx][nexty] += (bowl[h][w] - bowl[nextx][nexty]) / 5;
					}
					else if (bowl[h][w] < bowl[nextx][nexty])
					{
						nextbowl[h][w] += (-bowl[h][w] + bowl[nextx][nexty]) / 5;
						nextbowl[nextx][nexty] -= (-bowl[h][w] + bowl[nextx][nexty]) / 5;
					}
				}
				i++;
			}
		}
		while (i < N - 1)
		{
			int nextx = N - 1;
			int nexty = i + 1;
			if (bowl[N - 1][i] > bowl[nextx][nexty])
			{
				nextbowl[N - 1][i] -= (bowl[N - 1][i] - bowl[nextx][nexty]) / 5;
				nextbowl[nextx][nexty] += (bowl[N - 1][i] - bowl[nextx][nexty]) / 5;
			}
			else if (bowl[N - 1][i] < bowl[nextx][nexty])
			{
				nextbowl[N - 1][i] += (-bowl[N - 1][i] + bowl[nextx][nexty]) / 5;
				nextbowl[nextx][nexty] -= (-bowl[N - 1][i] + bowl[nextx][nexty]) / 5;
			}
			i++;
		}
		i = 0;
		for (int w = left; w < left + cnt; w++)
		{
			for (int h = N - 1; h > N - 1 - high; h--)
			{
				bowl[h][w] += nextbowl[h][w];
				nextbowl[h][w] = 0;
				i++;
			}
		}
		while (i < N)
		{
			bowl[N - 1][i] += nextbowl[N - 1][i];
			nextbowl[N - 1][i] = 0;
			i++;
		}
		//그림 8
		i = 0;
		for (int w = left; w < left + cnt; w++)
		{
			for (int h = N - 1; h > N - 1 - high; h--)
			{
				if (h == N - 1 && i == w)
				{
					i++;
					continue;
				}
				bowl[N - 1][i] = bowl[h][w];
				bowl[h][w] = 0;
				i++;
			}
		}
		//그림 9번
		for (i = 0; i < N / 2; i++)
		{
			bowl[N - 2][N - 1 - i] = bowl[N - 1][i];
			bowl[N - 1][i] = 0;
		}
		//그림 10번
		for (i = N / 2; i < 3 * N / 4; i++)
		{
			for (int j = N - 2; j <= N - 1; j++)
			{
				bowl[2 * N - j - 5][3 * N / 2 - 1 - i] = bowl[j][i];
				bowl[j][i] = 0;
			}
		}
		for (i = N - 4; i <= N - 1; i++)
		{
			for (int j = 3 * N / 4; j <= N - 1; j++)
			{
				for (int k = 2; k <= 3; k++)
				{
					int nextx = i + dx[k];
					int nexty = j + dy[k];
					if (nextx<0 || nextx>=N || nexty<0 || nexty>=N)continue;
					if (!bowl[nextx][nexty])continue;
					if (bowl[i][j] > bowl[nextx][nexty])
					{
						nextbowl[i][j] -= (bowl[i][j] - bowl[nextx][nexty]) / 5;
						nextbowl[nextx][nexty] += (bowl[i][j] - bowl[nextx][nexty]) / 5;
					}
					else if (bowl[i][j] < bowl[nextx][nexty])
					{
						nextbowl[i][j] += (-bowl[i][j] + bowl[nextx][nexty]) / 5;
						nextbowl[nextx][nexty] -= (-bowl[i][j] + bowl[nextx][nexty]) / 5;
					}
				}
			}
		}
		int x = 0;
		Min = 10000;
		Max = 0;
		for (int j = 3 * N / 4; j < N; j++)
		{
			for (i = N - 1; i >= N - 4; i--)
			{
				bowl[i][j] += nextbowl[i][j];
				Min = min(Min, bowl[i][j]);
				Max = max(Max, bowl[i][j]);
				nextbowl[i][j] = 0;
				if (i == N - 1 && j == x)
				{
					x++;
					continue;
				}
				bowl[N - 1][x++] = bowl[i][j];
				bowl[i][j] = 0;
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}