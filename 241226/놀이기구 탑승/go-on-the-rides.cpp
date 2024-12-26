#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;
int n, table[22][22], dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
unordered_map<int, int> keys;
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int p = 0; p < n * n; p++) {
		int n0, num;
		cin >> n0;
		for (int k = 0; k < 4; k++) {
			cin >> num;
			keys[n0 * 401 + num] = 1;
		}
		priority_queue<tuple<int, int, int, int>> pq;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (table[i][j])continue;
				int friends = 0;
				int empty = 0;
				for(int k=0;k<4;k++){
					int nextx = i + dx[k];
					int nexty = j + dy[k];
					if (nextx >= 1 and nextx <= n and nexty >= 1 and nexty <= n) {
						if (!table[nextx][nexty])empty++;
						if (keys[n0 * 401 + table[nextx][nexty]])friends++;
					}
				}
				pq.push(make_tuple(friends, empty, -i, -j));
			}
		}
		int x = -get<2>(pq.top());
		int y = -get<3>(pq.top());
		table[x][y] = n0;
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int friends = 0;
			for (int k = 0; k < 4; k++) {
				int nextx = i+dx[k];
				int nexty = j+dy[k];
				friends += keys[table[i][j] * 401 + table[nextx][nexty]];
			}
			if (friends == 1)answer++;
			else if (friends == 2)answer += 10;
			else if (friends == 3)answer += 100;
			else if (friends == 4)answer += 1000;
		}
	}
	cout << answer;
	return 0;
}