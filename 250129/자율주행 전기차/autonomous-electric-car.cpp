#include <iostream>
#include <deque>
#include <tuple>
#include <queue>
using namespace std;
int N, M,gas,x,y;
int destinations[401][2],taximap[21][21];
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };
int whereiscustomer() {
	bool check[21][21] = { false };
	check[x][y] = true;
	priority_queue<tuple<int, int, int>> pq;
	pq.push(make_tuple(0,-x, -y));
	while (!pq.empty()) {
		int i = -get<1>(pq.top());
		int j = -get<2>(pq.top());
		int t = -get<0>(pq.top());
		if (taximap[i][j]) {
			x = i;
			y = j;
			gas -= t;
			int answer = taximap[i][j];
			taximap[i][j] = 0;
			return answer;
		}
		pq.pop();
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
				if (!check[nx][ny] && taximap[nx][ny] != -1) {
					check[nx][ny] = true;
					pq.push(make_tuple(-t-1,-nx, -ny));
				}
			}
		}
	}
	return -1;
}
void godestination(int cnum) {
	int destx = destinations[cnum][0];
	int desty = destinations[cnum][1];
	bool check[21][21] = { false };
	check[x][y] = true;
	deque<tuple<int, int, int>> dq;
	dq.push_back(make_tuple(x, y, 0));
	while (!dq.empty()) {
		int i = get<0>(dq.front());
		int j = get<1>(dq.front());
		int t = get<2>(dq.front());
		dq.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
				if (!check[nx][ny] && taximap[nx][ny] != -1) {
					if (nx==destx && ny==desty) {
						x = nx;
						y = ny;
						if (gas >= t + 1)gas += t + 1;
						else gas -= t + 1;
						return;
					}
					check[nx][ny] = true;
					dq.push_back(make_tuple(nx, ny, t + 1));
				}
			}
		}
	}
	gas = 0;
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M>>gas;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> taximap[i][j];
			if (taximap[i][j])taximap[i][j] = -1;
		}
	}
	cin >> x >> y;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b >> destinations[i][0] >> destinations[i][1];
		taximap[a][b] = i;
	}
	for (int tc = 1; tc <= M; tc++) {
		int cnum=whereiscustomer();
		if (gas <= 0 || cnum==-1) {
			cout << -1;
			return 0;
		}
		godestination(cnum);
		if (gas <= 0) {
			cout << -1;
			return 0;
		}
	}
	cout << gas;
	return 0;
}