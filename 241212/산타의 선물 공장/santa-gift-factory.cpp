#include <iostream>
#include <list>
#include <unordered_map>
int boxes[100000];
int weights[100000];
using namespace std;
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q,n,m,w_max,answer=0,r_id,f_id,b_num;
	cin >> q;
	list<pair<int,int>> belt[11];
	bool available[11] = { false };
	unordered_map<int, int> lines;
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
					lines[boxes[j]] = i;
				}
			}
			break;
		case 200:
			answer=0;
			cin >> w_max;
			for (int i = 1; i <= m; i++) {
				if (belt[i].empty())continue;
				if (belt[i].front().second <= w_max) {
					lines[belt[i].front().first] = 0;
					answer += belt[i].front().second;
				}
				else belt[i].push_back(belt[i].front());
				belt[i].pop_front();
			}
			cout << answer << "\n";
			break;
		case 300:
			cin >> r_id;
			if (lines[r_id] == 0)cout << -1 << "\n";
			else {
				int l = lines[r_id];
				lines[r_id] = 0;
				auto it = belt[l].begin();
				while ((*it).first != r_id)it++;
				belt[l].erase(it);
				cout << r_id << "\n";
			}
			break;
		case 400:
			cin >> f_id;
			if (lines[f_id] == 0)cout << "-1\n";
			else {
				int l = lines[f_id];
				auto it = belt[l].begin();
				while ((*it).first != f_id)it++;
				belt[l].splice(belt[l].begin(), belt[l], it, belt[l].end());
				cout << l << "\n";
			}
			break;
		case 500:
			cin >> b_num;
			if (available[b_num] == false)cout << "-1\n";
			else {
				available[b_num] = false;
				int l=b_num;
				while (!available[l]) {
					l++;
					if (l > m)l = 1;
				}
				for (auto i : belt[b_num])lines[i.first] = l;
				belt[l].splice(belt[l].end(), belt[b_num]);
				cout << b_num << "\n";
			}
			break;
		}
	}
	return 0;
}
