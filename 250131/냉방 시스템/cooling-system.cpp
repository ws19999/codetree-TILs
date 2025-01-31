#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
using namespace std;
int N;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
struct cooler {
	int x, y, dir;
};
vector<cooler> coolers;
vector<pair<int, int>> office;
int cool[21][21];
int walls[21][21];

void make_walls(int W) {
	int x, y, t;
	for (int i = 0; i < W; i++) {
		cin >> x >> y >> t;
		if (t == 0) {
			walls[x][y] += 1;
			walls[x - 1][y] += 4;
		}
		else {
			walls[x][y] += 8;
			walls[x][y - 1] += 2;
		}
	}
}

void tempup(int x, int y, int dir) {
	int nx, ny;
	deque<tuple<int, int, int>> dq;
	bool visited[21][21] = { false };
	visited[x][y] = true;
	cool[x][y] += 5;
	dq.push_back(make_tuple(x, y, 4));
	while (!dq.empty()) {
		x = get<0>(dq.front());
		y = get<1>(dq.front());
		int num = get<2>(dq.front());
		dq.pop_front();
		nx = x + dx[dir] + dx[(dir + 3) % 4];
		ny = y + dy[dir] + dy[(dir + 3) % 4];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if (!visited[nx][ny] && !(walls[x][y] & 1 << (dir + 3) % 4) && !(walls[x + dx[(dir + 3) % 4]][y + dy[(dir + 3) % 4]] & 1 << dir)) {
				visited[nx][ny] = true;
				cool[nx][ny] += num;
				if (num)dq.push_back(make_tuple(nx, ny, num - 1));
			}
		}
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if (!visited[nx][ny] && !(walls[x][y] & 1 << dir)) {
				visited[nx][ny] = true;
				cool[nx][ny] += num;
				if (num)dq.push_back(make_tuple(nx, ny, num - 1));
			}
		}
		nx = x + dx[dir] + dx[(dir + 1) % 4];
		ny = y + dy[dir] + dy[(dir + 1) % 4];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if (!visited[nx][ny] && !(walls[x][y] & 1 << (dir + 1) % 4) && !(walls[x + dx[(dir + 1) % 4]][y + dy[(dir + 1) % 4]] & 1 << dir)) {
				visited[nx][ny] = true;
				cool[nx][ny] += num;
				if (num)dq.push_back(make_tuple(nx, ny, num - 1));
			}
		}
	}
}

void wind() {
	for (auto machine : coolers) {
		int x = machine.x + dx[machine.dir];
		int y = machine.y + dy[machine.dir];
		int dir = machine.dir;
		tempup(x, y, dir);
	}
}

void temp_mixing() {
	int changes[21][21] = { 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp = cool[i][j];
			for (int k = 0; k < 4; k++) {
				if (walls[i][j] & 1 << k)continue;
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
					int t = cool[nx][ny];
					if (t > temp)changes[i][j] += (t - temp) / 4;
					else if (t < temp)changes[i][j] -= (temp - t) / 4;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)cool[i][j] += changes[i][j];
	}
}

void temp_decreased() {
	int x = 1, y = 1, dir = 1;
	for (int cnt = 1; cnt <= 2 * N + 2 * N - 4; cnt++) {
		if (cool[x][y])cool[x][y]--;
		x += dx[dir];
		y += dy[dir];
		if (x <= 0 || x > N || y <= 0 || y > N) {
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 1) % 4;
			x += dx[dir];
			y += dy[dir];
		}
	}
}

bool temp_check(int K) {
	for (auto p : office) {
		if (cool[p.first][p.second] < K)return false;
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, W;
	cin >> N >> W >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			if (2 <= num) {
				cooler machine;
				machine.x = i;
				machine.y = j;
				machine.dir = (num + 1) % 4;
				coolers.push_back(machine);
			}
			else if (num == 1)office.push_back(make_pair(i, j));
		}
	}
	make_walls(W);
	for (int t = 1; t <= 100; t++) {
		wind();
		temp_mixing();
		temp_decreased();
		if (temp_check(K)) {
			cout << t;
			return 0;
		}
	}
	cout << -1;
	return 0;
}