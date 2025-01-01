#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int L, Q,초밥개수=0,사람수=0,이전시간=0;
unordered_map<string, pair<int, int>> person;
unordered_map<string, unordered_map<int, int>> sushi;
void timewarp(int t) {
	vector<string> leaving;
	// t-이전시간>=L이면 다 먹기.
	// 
	// 아니면 
	

	if (t - 이전시간 >= L) {
		for (auto p : person) {
			vector<int> leave;
			for (auto i: sushi[p.first]) {
				//if (person[p.first].second < i.second) {
					//sushi[p.first][i.first] -= person[p.first].second;
					//초밥개수 -= person[p.first].second;
					//person[p.first].second = 0;
					//break;
				//}
				person[p.first].second -= i.second;
				초밥개수 -= i.second;
				sushi[p.first][i.first] = 0;
				leave.push_back(i.first);
				if (person[p.first].second <= 0)break;
			}
			for (auto i : leave) {
				sushi[p.first].erase(i);
			}
			if (person[p.first].second == 0) {
				leaving.push_back(p.first);
				사람수--;
			}
		}
	}
	else {
		for (auto p : person) {
			vector<int> leave;
			for (auto i : sushi[p.first]) {
				if (((i.first + t) % L > (i.first + 이전시간) % L and p.second.first <= (i.first + t) % L and p.second.first > (i.first + 이전시간) % L) or ((i.first + t) % L < (i.first + 이전시간) % L and (p.second.first <= (i.first + t) % L or p.second.first > (i.first + 이전시간) % L))) {
					//if (person[p.first].second < i.second) {
						//sushi[p.first][i.first] -= person[p.first].second;
						//초밥개수 -= person[p.first].second;
						//person[p.first].second = 0;
						//break;
					//}
					person[p.first].second -= i.second;
					초밥개수 -= i.second;
					sushi[p.first][i.first] = 0;
					leave.push_back(i.first);
					if (person[p.first].second <= 0)break;
				}
			}
			for (auto i : leave) {
				sushi[p.first].erase(i);
			}
			if (person[p.first].second == 0) {
				leaving.push_back(p.first);
				사람수--;
			}
		}
	}
	for (auto i : leaving)person.erase(i);
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> L >> Q;
	
	for (int tc = 1; tc <= Q; tc++) {
		int q,t=0,x;
		string name;
		cin >> q;
		if (q == 100) {
			cin >> t>>x>>name;
			sushi[name][((x-t)%L+L)%L]++;
			초밥개수++;
			timewarp(t);
		}
		else if (q == 200) {
			int n;
			cin >> t >>x>> name >> n;
			person[name]=make_pair(x,n);
			사람수++;
			timewarp(t);
		}
		else if (q == 300) {
			cin >> t;
			timewarp(t);
			cout << 사람수 << " " << 초밥개수 << "\n";
		}
		이전시간 = t;
	}
	return 0;
}