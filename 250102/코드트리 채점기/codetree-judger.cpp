#include <iostream>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
unordered_map<string, int> domain;
unordered_map<string, int> url;
bool urls[50001];
int domainhistory[301][2];
priority_queue<int> 채점기;
int 채점중[50001];  // 채점기,도메인
int 채점중도메인[301]; //도메인 1
priority_queue<tuple<int, int, int>> pq[301]; // -우선,-큐 시간, url id
int domainnum = 1;
int urlnum = 1;
int task = 0;
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q,N=0;
	cin >> Q;
	for (int tc = 1; tc <= Q; tc++) {
		int q;
		cin >> q;
		if (q == 100) {
			cin >> N;
			for (int i = N; i >= 1; i--)채점기.push(-i);
			string u0; //도메인/문제ID
			cin >> u0;
			url[u0] = urlnum++;
			string str = "";
			for (auto i : u0) {
				if (i == '/')break;
				str += i;
			}
			domain[str] = domainnum++;
			pq[1].push(make_tuple(-1, 0, 1));
			urls[1] = true;
			task++;
		}
		else if (q == 200) {
			int t, p, d;
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
			pq[d].push(make_tuple(-p, -t, urln));
		}
		else if (q == 300) { //채점 가능한 것 중에서 우선순위가 가장 높은 task 채점.
			//채점 진행중인 도메인 있으면 패스. 일치 도메인 주에서 start + 3*gap 보다 작으면 패스.
			//p가 작을수록 우선순위. 큐에 들어온 시간이 빠를수록.
			//번호가 가장 작은 것이 우선순위 채점 시작.
			int t;
			cin >> t;
			int nextone=0,priority = 99999999,qt=99999999;
			for (int i = 1; i <domainnum; i++) {
				if (채점중도메인[i] or t < domainhistory[i][0] + 3 * domainhistory[i][1] or pq[i].empty())continue;
				if (priority > -get<0>(pq[i].top()) or (priority == -get<0>(pq[i].top()) and qt > -get<1>(pq[i].top()))) {
					nextone = i;
					priority = -get<0>(pq[i].top());
					qt = -get<1>(pq[i].top());
				}
			}
			if (!채점기.empty() and nextone) {
				urls[get<2>(pq[nextone].top())] = false;
				int chae = -채점기.top();
				채점기.pop();
				채점중[chae] = nextone;
				domainhistory[nextone][0] = t;
				채점중도메인[nextone] = 1;
				pq[nextone].pop();
				task--;
			}
		}
		else if (q == 400) { //J_id가 비어있으면 패스. 아니면 종료하고 쉼.
			int t, J_id;
			cin >> t >> J_id;
			if (채점중[J_id]) {
				int dnum = 채점중[J_id];
				채점중[J_id] = 0;
				채점중도메인[dnum] = 0;
				domainhistory[dnum][1] = t - domainhistory[dnum][0];
				채점기.push(-J_id);
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