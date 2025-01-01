#include <iostream>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
unordered_map<string, int> domain; 
unordered_map<string, int> url;
bool urls[50001];
priority_queue<tuple<int, int, int,int>> pq; //-우선순위, -큐 시간, 도메인 id , url id
unordered_map<int, pair<int, int>> domainhistory;
priority_queue<int> 채점기;
unordered_map<int, int> 채점중;  // 채점기,도메인
unordered_map<int, int> 채점중도메인; //도메인 1
priority_queue<tuple<int,int, int, int>> impossible[50001]; // -우선,-큐 시간, 도메인 id, url id
priority_queue<pair<int, int>> 가능시간; // -시간,도메인
int domainnum = 1;
int urlnum = 1;
int task = 0;
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q;
	cin >> Q;
	for (int tc = 1; tc <= Q; tc++) {
		int N,q;
		cin >> q;
		if (q == 100) {
			cin >> N;
			for (int i = N; i >= 1; i--)채점기.push(-i);
			string u0; //도메인/문제ID
			cin >> u0;
			url[u0] = urlnum++;
			string str="";
			for (auto i : u0) {
				if (i == '/')break;
				str += i;
			}
			domain[str] = domainnum++;
			pq.push(make_tuple(-1, 0, 1,1));
			urls[1] = true;
			task++;
		}
		else if (q == 200) {
			int t, p,d;
			string u; //정확히 일치하는 url이 하나라도 있으면 패스.
			cin >> t >> p >> u;
			if (urls[url[u]])continue;
			task++;
			int urln = urlnum;
			if (!url[u])url[u] = urlnum++;
			else urln = url[u];
			string str = "";
			for (auto i : u) {
				if (i == '/')break;
				str += i;
			}
			if (!domain[str]) {
				domain[str] = domainnum++;
				d = domainnum - 1;
			}
			else d = domain[str];
			urls[urln] = true;
			if (채점중도메인[d] or t<3*domainhistory[d].second-2*domainhistory[d].first) {
				impossible[d].push(make_tuple(-p, -t, d, urln));
			}
			else pq.push(make_tuple(-p, -t, d, urln));
		}
		else if (q == 300) { //채점 가능한 것 중에서 우선순위가 가장 높은 task 채점.
			//채점 진행중인 도메인 있으면 패스. 일치 도메인 주에서 start + 3*gap 보다 작으면 패스.
			//p가 작을수록 우선순위. 큐에 들어온 시간이 빠를수록.
			//번호가 가장 작은 것이 우선순위 채점 시작.
			int t;
			cin >> t;
			while (!가능시간.empty()) {
				if (-가능시간.top().first <= t) {
					int dnum = 가능시간.top().second;
					가능시간.pop();
					if (!impossible[dnum].empty()) {
						pq.push(impossible[dnum].top());
						impossible[dnum].pop();
					}
				}
				else break;
			}
			while (!채점기.empty()) {
				if (pq.empty())break;
				int dnum = get<2>(pq.top());
				urls[get<3>(pq.top())]=false;
				int chae = -채점기.top();
				채점기.pop();
				채점중[chae] = dnum;
				domainhistory[dnum].first = t;
				채점중도메인[dnum] = 1;
				pq.pop();
				task--;
				break;
			}
		}
		else if (q == 400) { //J_id가 비어있으면 패스. 아니면 종료하고 쉼.
			int t, J_id;
			cin >> t >> J_id;
			if (채점중[J_id]) {
				int dnum = 채점중[J_id];
				채점중[J_id] = 0;
				채점중도메인[dnum] = 0;
				domainhistory[dnum].second = t;
				채점기.push(-J_id);
				가능시간.push(make_pair(-3 * t + 2*domainhistory[dnum].first, dnum));
			}
		}
		else {
			int t;
			cin >> t;
			cout << task << "\n";
		}
	}
	return 0;
}