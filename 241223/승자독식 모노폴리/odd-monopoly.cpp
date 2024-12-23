#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;
pair<int, int> table[20][20];
int n, m, k;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int dirs[401][5][4];
map<int, tuple<int, int, int>> players;
void turn(int t) {
	vector<int> erase;
	for (auto player : players) {
		int x = get<0>(player.second);
		int y = get<1>(player.second);
		int d = get<2>(player.second);
		int num = player.first;
		bool moved = false;
		for (int i = 0; i < 4; i++) {
			int nextx = x+dx[dirs[num][d][i]];
			int nexty = y + dy[dirs[num][d][i]];
			if (nextx >= 0 and nextx < n and nexty >= 0 and nexty < n) {
				if (t - table[nextx][nexty].second > k or table[nextx][nexty].first==0) {
					moved = true;
					players[player.first] = make_tuple(nextx, nexty, dirs[num][d][i]);
					table[nextx][nexty] = make_pair(player.first, t);
					break;
				}
				if (t == table[nextx][nexty].second) {
					if (table[nextx][nexty].first > player.first) {
						moved = true;
						erase.push_back(table[nextx][nexty].first);
						players[player.first] = make_tuple(nextx, nexty, dirs[num][d][i]);
						table[nextx][nexty] = make_pair(player.first, t);
						break;
					}
					else {
						moved = true;
						erase.push_back(player.first);
						break;
					}
				}
			}
		}
		if (!moved) {
			for (int i = 0; i < 4; i++) {
				int nextx = x + dx[dirs[num][d][i]];
				int nexty = y + dy[dirs[num][d][i]];
				if (nextx >= 0 and nextx < n and nexty >= 0 and nexty < n) {
					if (table[nextx][nexty].first == player.first) {
						table[nextx][nexty].second = t+1;
						players[player.first] = make_tuple(nextx, nexty, dirs[num][d][i]);
						break;
					}
				}
			}
		}
	}
	for (auto i : erase) {
		players.erase(i);
		m--;
	}
	for (auto p : players) {
		table[get<0>(p.second)][get<1>(p.second)].second = t;
	}
}
void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (num) {
				table[i][j] = make_pair(num, 0);
				players[num] = make_tuple(i, j, 0);
			}
		}
	}
	for (int i = 1; i <= m; i++)cin >> get<2>(players[i]);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int l = 0; l < 4; l++)cin >> dirs[i][j][l];
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	for (int t = 1; t < 1000; t++) {
		turn(t);
		if (m == 1) {
			cout << t;
			return 0;
		}
	}
	cout << -1;
	return 0;
}