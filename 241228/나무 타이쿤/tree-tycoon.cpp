#include <iostream>
#include <deque>
using namespace std;
int n, m;
int dx[] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[] = { 0,1,1,0,-1,-1,-1,0,1 };
int dxx[] = { -1,1,-1,1 };
int dyy[] = { -1,1,1,-1 };
int worlds[15][15];
deque < pair<int, int>> dq;
int tonic[15][15] ;
void year(int d, int p) {
	int trees = dq.size();
	for (int i = 0; i < trees; i++) {
		tonic[dq[i].first][dq[i].second] --;
		dq[i].first += dx[d] * p;
		dq[i].second += dy[d] * p;
		dq[i].first %= n;
		if (dq[i].first < 0)dq[i].first +=n;
		dq[i].second %= n;
		if (dq[i].second < 0)dq[i].second += n;
		tonic[dq[i].first][dq[i].second] ++;
		worlds[dq[i].first][dq[i].second]++;
	}
	for (int i = 0; i < trees; i++) {
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int nextx = dq[i].first + dxx[k];
			int nexty = dq[i].second + dyy[k];
			if (nextx >= 0 and nextx < n and nexty >= 0 and nexty < n) {
				if (worlds[nextx][nexty])cnt++;
			}
		}
		worlds[dq[i].first][dq[i].second] += cnt;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (worlds[i][j] >= 2 and !tonic[i][j]) {
				worlds[i][j] -= 2;
				tonic[i][j] = 1;
				dq.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < trees; i++) {
		tonic[dq.front().first][dq.front().second] = 0;
		dq.pop_front();
	}
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> worlds[i][j];
		}
	}
	for (int i = n - 2; i <= n - 1; i++) {
		for (int j = 0; j <= 1; j++) {
			tonic[i][j] = 1;
			dq.push_back(make_pair(i, j));
		}
	}
	for (int y = 1; y <= m; y++) {
		int d, p;
		cin >> d >> p;
		year(d, p);
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)answer += worlds[i][j];
	}
	cout << answer;
	return 0;
}