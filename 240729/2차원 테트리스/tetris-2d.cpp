#include <iostream>
using namespace std;
int red[4][7];
int yellow[7][4];
int redscore[6];
int yellowscore[6];
int answer = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		red[i][6] = 1;
		yellow[6][i] = 1;
	}
	int k;
	cin >> k;
	for (int tc = 0; tc < k; tc++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
		{
			for (int i = 1; i < 6; i++)
			{
				if (red[x][i + 1])
				{
					if (i == 1)break;
					red[x][i] = 1;
					redscore[i]++;
					if (redscore[i] == 4)
					{
						answer++;
						for (int j = i - 1; j >= 1; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								red[k][j + 1] = red[k][j];
							}
							redscore[j + 1] = redscore[j];
						}
					}
					break;
				}
			}

			for (int i = 1; i < 6; i++)
			{
				if (yellow[i + 1][y])
				{
					if (i == 1)break;
					yellow[i][y] = 1;
					yellowscore[i]++;
					if (yellowscore[i] == 4)
					{
						answer++;
						for (int j = i - 1; j >= 1; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								yellow[j + 1][k] = yellow[j][k];
							}
							yellowscore[j + 1] = yellowscore[j];
						}
					}
					break;
				}
			}

		}
		else if (t == 2)
		{
			for (int i = 1; i < 6; i++)
			{
				if (red[x][i + 1])
				{
					if (i == 1)break;
					red[x][i] = 1;
					red[x][i - 1] = 1;
					redscore[i]++;
					redscore[i - 1]++;
					if (redscore[i] == 4 and redscore[i - 1] == 4)
					{
						answer += 2;
						for (int j = i - 2; j >= 0; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								red[k][j + 2] = red[k][j];
							}
							redscore[j + 2] = redscore[j];
						}
					}
					else if (redscore[i] == 4)
					{
						answer++;
						for (int j = i - 1; j >= 0; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								red[k][j + 1] = red[k][j];
							}
							redscore[j + 1] = redscore[j];
						}
					}
					else if (redscore[i - 1] == 4)
					{
						answer++;
						for (int j = i - 2; j >= 0; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								red[k][j + 1] = red[k][j];
							}
							redscore[j + 1] = redscore[j];
						}
					}
					break;
				}
			}
			for (int j = 0; j < 2; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					red[i][j] = 0;
				}
				redscore[j] = 0;
			}
			for (int i = 1; i < 6; i++)
			{
				if (yellow[i + 1][y] == 1 or yellow[i + 1][y + 1] == 1)
				{
					if (i == 1)continue;
					yellow[i][y] = 1;
					yellow[i][y + 1] = 1;
					yellowscore[i] += 2;
					if (yellowscore[i] == 4)
					{
						for (int j = i - 1; j >= 1; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								yellow[j + 1][k] = yellow[j][k];
							}
							yellowscore[j + 1] = yellowscore[j];
						}
					}
					break;
				}
			}
		}
		else if (t == 3)
		{
			for (int i = 1; i < 6; i++)
			{
				if (yellow[i + 1][y])
				{
					if (i == 1)break;
					yellow[i][y] = 1;
					yellow[i - 1][y] = 1;
					yellowscore[i]++;
					yellowscore[i - 1]++;
					if (yellowscore[i] == 4 and yellowscore[i - 1] == 4)
					{
						answer += 2;
						for (int j = i - 2; j >= 0; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								yellow[j + 2][k] = yellow[j][k];
							}
							yellowscore[j + 2] = yellowscore[j];
						}
					}
					else if (yellowscore[i] == 4)
					{
						answer++;
						for (int j = i - 1; j >= 0; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								yellow[k][j + 1] = yellow[k][j];
							}
							yellowscore[j + 1] = yellowscore[j];
						}
					}
					else if (yellowscore[i - 1] == 4)
					{
						answer++;
						for (int j = i - 2; j >= 0; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								yellow[j + 1][k] = yellow[j][k];
							}
							yellowscore[j + 1] = yellowscore[j];
						}
					}
					break;
				}
			}
			for (int j = 0; j < 2; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					yellow[j][i] = 0;
				}
				yellowscore[j] = 0;
			}
			for (int i = 1; i < 6; i++)
			{
				if (red[x][i + 1] == 1 or red[x + 1][i + 1] == 1)
				{
					if (i == 1)continue;
					red[x][i] = 1;
					red[x + 1][i] = 1;
					redscore[i] += 2;
					if (redscore[i] == 4)
					{
						answer++;
						for (int j = i - 1; j >= 1; j--)
						{
							for (int k = 0; k < 4; k++)
							{
								red[k][j + 1] = red[k][j];
							}
							redscore[j + 1] = redscore[j];
						}
					}
					break;
				}
			}
		}
	}
	int answer2 = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 6; j++)
		{
			if (red[i][j])answer2++;
			if (yellow[j][i])answer2++;
		}
	}
	cout << answer << "\n" << answer2;
	return 0;
}