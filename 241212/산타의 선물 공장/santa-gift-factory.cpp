#include <iostream>
#include <list>
#include <unordered_map>
int boxes[100000];
int weights[100000];
using namespace std;
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q, n, m, w_max, answer = 0, r_id, f_id, b_num;
	cin >> q;
	list<pair<int, int>> belt[11];
	bool available[11] = { false };
	unordered_map<int, pair<int,list<pair<int, int>>::iterator>> keys;
	for (int query = 1; query <= q; query++) {
		int Q;
		cin >> Q;
		switch (Q) {
		case 100:
			cin >> n >> m;
			for (int i = 0; i < n; i++)cin >> boxes[i];
			for (int i = 0; i < n; i++) cin >> weights[i];
			for (int i = 1; i <= m; i++) {
				available[i] = true;
				for (int j = (i - 1) * n / m; j < i * n / m; j++) {
					belt[i].push_back(make_pair(boxes[j], weights[j]));
					auto it = belt[i].end();
					it--;
					keys[boxes[j]] = make_pair(i,it);
				}
			}
			break;
		case 200:
			answer = 0;
			cin >> w_max;
			for (int i = 1; i <= m; i++) {
				if (belt[i].empty())continue;
				if (belt[i].front().second <= w_max) {
					keys[belt[i].front().first].first = 0;
					answer += belt[i].front().second;
				}
				else{
					belt[i].push_back(belt[i].front());
					auto it = belt[i].end();
					it--;
					keys[belt[i].front().first].second = it;
				}
				belt[i].pop_front();
			}
			cout << answer << "\n";
			break;
		case 300:
			cin >> r_id;
			if (keys[r_id].first == 0)cout << -1 << "\n";
			else {
				int l = keys[r_id].first;
				keys[r_id].first = 0;
				belt[l].erase(keys[r_id].second);
				cout << r_id << "\n";
			}
			break;
		case 400:
			cin >> f_id;
			if (keys[f_id].first == 0)cout << "-1\n";
			else {
				int l = keys[f_id].first;
				belt[l].splice(belt[l].begin(), belt[l], keys[f_id].second, belt[l].end());
				cout << l << "\n";
			}
			break;
		case 500:
			cin >> b_num;
			if (available[b_num] == false)cout << "-1\n";
			else {
				available[b_num] = false;
				int l = b_num;
				while (!available[l]) {
					l++;
					if (l > m)l = 1;
				}
				for (auto i : belt[b_num])keys[i.first].first = l;
				belt[l].splice(belt[l].end(), belt[b_num]);
				cout << b_num << "\n";
			}
			break;
		}
	}
	return 0;
}
