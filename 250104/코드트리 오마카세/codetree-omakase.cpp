#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
unordered_map<string, int> 이름;
vector <pair<int,int>> 초밥[15001];
int 손님[15001][2];
priority_queue<pair<int, int>> pq;
int L,namecnt=1,손님수=0,초밥수=0;
void timepast(int t) {
	while (!pq.empty()) {
		if (-pq.top().first > t)break;
		손님[pq.top().second][1]--;
		if (손님[pq.top().second][1] == 0)손님수--;
		pq.pop();
		초밥수--;
	}
}
void pqq(int pos, int x,int t,int namenum) {
	if (x <= pos)pq.push(make_pair(-(t + pos - x), namenum));
	else pq.push(make_pair(-(t + L - x + pos), namenum));
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q;
	cin >>L>> Q;
	for (int q = 1; q <= Q; q++) {
		int order,t;
		string name;
		cin >> order;
		if (order == 100) {
			int x;
			cin >> t >>x>> name;
			초밥수++;
			int num = 이름[name];
			if (!이름[name]) {
				이름[name] = namecnt++;
				num = namecnt - 1;
			}
			if(손님[num][1]){
				int pos = 손님[num][0];
				pqq(pos, x, t, num);
			}
			else {
				초밥[num].push_back(make_pair(t, x));
			}
			timepast(t);
		}
		else if (order == 200) { 
			손님수++;
			int x,n,num;
			cin >> t >>x>> name>>n;
			num = 이름[name];
			if (!이름[name]) {
				이름[name] = namecnt++;
				num = namecnt - 1;
			}
			손님[num][1] = n;
			손님[num][0] = x;
			while (!초밥[num].empty()) {
				int pos = (t-초밥[num].back().first + 초밥[num].back().second)%L;
				pqq(x, pos, t, num);
				초밥[num].pop_back();
			}
			timepast(t);
		}
		else if (order == 300) {
			cin >> t;
			timepast(t);
			cout << 손님수 << " " << 초밥수 << "\n";
		}
	}
	return 0;
}