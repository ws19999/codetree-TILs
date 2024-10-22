#include <iostream>
#include <list>
#include <deque>
#include <tuple>
using namespace std;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int dxx[] = { -1,-1,0,1,1,1,0,-1 }, dyy[] = { 0,1,1,1,0,-1,-1,-1 };
int N, M, sr, sc, er, ec,rock,dists,attacks,dirr, vil[50][50];;
deque<pair<int, int>> medusa;
int village[50][50];
list <pair<int, int>> warriors;
int move(int x,int y,int i)
{
	for (int t = i; t < i + 4; t++)
	{
		int k = t % 4;
		int nextx = x + dx[k];
		int nexty = y + dy[k];
		if (abs(nextx - sr) + abs(nexty - sc) < abs(x - sr) + abs(y - sc))
		{
			if (nextx >= 0 and nextx < N and nexty >= 0 and nexty < N)
			{
				int cur = vil[nextx][nexty];
				if (cur != dirr and cur != (dirr + 1) % 8 and cur != (dirr + 2) % 8 and cur != dirr + 8 and cur != (dirr + 9) % 8 + 8)return k;
			}
		}
	}
	return -1;
}
void route()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)vil[i][j] = -1;
	}
	vil[sr][sc] = -2;
	deque<pair<int, int>> dq;
	dq.push_back(make_pair(sr, sc));
	while (!dq.empty())
	{
		int x = dq.front().first, y = dq.front().second;
		dq.pop_front();
		if (x == er and y == ec)break;
		for (int k = 0; k < 4; k++)
		{
			int nextx = x + dx[k];
			int nexty = y + dy[k];
			if (nextx >= 0 and nexty >= 0 and nextx < N and nexty < N)
			{
				if (vil[nextx][nexty] == -1 and !village[nextx][nexty])
				{
					dq.push_back(make_pair(nextx, nexty));
					vil[nextx][nexty] = (5-k) % 4;
				}
			}
		}
	}
	int x = er, y = ec;
	if (vil[x][y] < 0)return;
	while (true)
	{
		medusa.push_front(make_pair(x, y));
		if (vil[x][y]==-2)return;
		int nextx = x + dx[vil[x][y]];
		int nexty = y + dy[vil[x][y]];
		x = nextx;
		y = nexty;
	}
}
void attack()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vil[i][j] = -2;
		}
	}
	int dir[16] = { 0 };
	for (int k = 0; k < 8; k++)
	{
		int x = sr;
		int y = sc;
		int look = k;
		while (x >= 0 and y >= 0 and x < N and y < N)
		{
			vil[x][y] = look;
			if (village[x][y] and look>=0)
			{
				look = -1;
				dir[k]+=village[x][y];
				if (k % 2 == 1)
				{
					deque<pair<int, int>> dq;
					dq.push_back(make_pair(x, y));
					while (!dq.empty())
					{
						int nx = dq.front().first;
						int ny = dq.front().second;
						dq.pop_front();
						for (int t = k - 1; t <= k + 1; t++)
						{
							int d = (t + 8) % 8;
							int nextx = nx + dxx[t];
							int nexty = ny + dyy[t];
							if (nextx >= 0 and nextx < N and nexty >= 0 and nexty < N)
							{
								if (vil[nextx][nexty] == -2)
								{
									vil[nextx][nexty] = -1;
									dq.push_back(make_pair(nextx, nexty));
								}
							}
						}
					}
					break;
				}
			}
			x += dxx[k];
			y += dyy[k];
		}
	}
	vil[sr][sc] = -1;
	for (int k = 0; k < 8; k++)
	{
		deque<pair<int, int>> dq;
		int x = sr;
		int y = sc;
		dq.push_back(make_pair(x + dxx[k], y + dyy[k]));
		dq.push_back(make_pair(x + dxx[(k+1)%8], y + dyy[(k+1)%8]));
		while (!dq.empty())
		{
			x = dq.front().first;
			y = dq.front().second;
			dq.pop_front();
			for (int i = 0; i < 2; i++)
			{
				int nextx = x + dxx[(k + i) % 8];
				int nexty = y + dyy[(k + i) % 8];
				if (nextx >= 0 and nextx < N and nexty >= 0 and nexty < N)
				{
					if (vil[nextx][nexty] == -2)
					{
						vil[nextx][nexty] = 8+k;
						if (village[nextx][nexty])
						{
							dir[8 + k] += village[nextx][nexty];
							deque<pair<int, int>> dqq;
							dqq.push_back(make_pair(nextx, nexty));
							while (!dqq.empty())
							{
								int nx = dqq.front().first;
								int ny = dqq.front().second;
								dqq.pop_front();
								for (int j = 0; j < 2; j++)
								{
									int nnx = nx + dxx[(k + j) % 8];
									int nny = ny + dyy[(k + j) % 8];
									if (nnx >= 0 and nnx < N and nny >= 0 and nny < N)
									{
										if (vil[nnx][nny] == -2)
										{
											dqq.push_back(make_pair(nnx, nny));
											vil[nnx][nny] = -1;
										}
									}
								}
							}
						}
						else dq.push_back(make_pair(nextx, nexty));
					}
				}
			}
		}
	}
	rock = 0;
	dists = 0;
	attacks = 0;
	dirr = 0;
	deque<int> nums;
	nums = { 7,3,5,1 };
	for (auto i:nums)
	{
		if (rock < dir[i] + dir[(i + 1)%8] + dir[(i + 2)%8] + dir[i + 8] + dir[(i + 9)%8+8])
		{
			rock = dir[i] + dir[(i + 1) % 8] + dir[(i + 2) % 8] + dir[i + 8] + dir[(i + 9) % 8 + 8];
			dirr = 4-(i+1)/2;
		}
	}
	dirr = 7 - 2 * dirr;
}
void move()
{
	auto it = warriors.begin();
	while (it != warriors.end())
	{
		int x = (*it).first;
		int y = (*it).second;
		int cur = vil[x][y];
		if (x == sr and y == sc)it = warriors.erase(it);
		else
		{
			if (cur != dirr and cur != (dirr + 1) % 8 and cur != (dirr + 2) % 8 and cur != dirr + 8 and cur != (dirr + 9) % 8 + 8)
			{
				int d = move(x, y, 0);
				if (d != -1)
				{
					village[x][y]--;
					x += dx[d];
					y += dy[d];
					dists++;
					d = move(x, y, 2);
					if (d != -1)
					{
						x += dx[d];
						y += dy[d];
						dists++;
					}
					village[x][y]++;
					(*it).first = x;
					(*it).second = y;
					if (x == sr and y == sc)
					{
						attacks++;
						village[x][y]--;
						it = warriors.erase(it);
					}
					else it++;
				}
				else it++;
			}
			else it++;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> sr >> sc >> er >> ec;
	for (int i = 0; i < M; i++)
	{
		int ar, ac;
		cin >> ar >> ac;
		warriors.push_back(make_pair(ar, ac));
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> village[i][j];
		}
	}
	route();
	if (medusa.empty())
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			village[i][j] = 0;
		}
	}
	for (auto i : warriors)
	{
		village[i.first][i.second]++;
	}
	while (true)
	{
		medusa.pop_front();
		sr = medusa.front().first;
		sc = medusa.front().second;
		if (sr==er and sc==ec)
		{
			cout << 0;
			return 0;
		}
		village[sr][sc] = 0;
		attack();
		move();
		cout << dists << " " << rock << " " << attacks << "\n";	
	}
	return 0;
}
/*
* 0~N-1 크기의 마을, 도로는 0, 도로가 아니면 1
* 집 S에서 공원 E까지 최단경로의 도로를 따라 이동.
* 초기에 전사들은 r,c에 있고 도로 상관없이 메두사 잡으러 최단경로로 이동.
* 
* 반복
* 1. 메두사가 이동. 전사가 있으면 사라짐. 상하좌우의 우선순위. 경로가 없을수도 있음(?)
* 2. 방향 하나 선택해서 바라봄 (전사를 가장 많이 볼 수 있는 방향) 똑같으면 상하좌우 우선순위.
시야각에 가려지는 조건 - 정확히 대각선, 애매, 완전 정방향 5개, 본 전사들은 돌로 변해서 이번엔 못움직임. 
3. 전사들의 이동 상하좌우 우선순위로 방향 선택. 시야 안으로는 못들어옴. 격자 바깥도 x -> 좌우상하로 한번더.
4. 메두사에 도착하면 사라짐.
매턴마다
모든 전사가 이동한 거리합
돌이 된 전사의 수
메두사를 공격한 전사의 수(죽은놈들)
공원에 도착하는 즉시 0출력하고 프로그램 종료.
N<=50 M<=300

메두사가 가는 경로는 미리 지정해놓기. bfs로 탐색후 이전값 저장해서 덱에 저장.
전사 관리 - 리스트로 관리, 지도에 표기.
*/