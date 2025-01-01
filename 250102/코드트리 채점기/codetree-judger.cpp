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
int domainnum = 1;
int urlnum = 1;
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
		}
		else if (q == 200) {
			int t, p,d;
			string u; //정확히 일치하는 url이 하나라도 있으면 패스.
			cin >> t >> p >> u;
			if (urls[url[u]])continue;
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
			pq.push(make_tuple(-p, -t, d, urln));
			//cout << urln << "\n";
		}
		else if (q == 300) { //채점 가능한 것 중에서 우선순위가 가장 높은 task 채점.
			//채점 진행중인 도메인 있으면 패스. 일치 도메인 주에서 start + 3*gap 보다 작으면 패스.
			//p가 작을수록 우선순위. 큐에 들어온 시간이 빠를수록.
			//번호가 가장 작은 것이 우선순위 채점 시작.
			int t;
			cin >> t;
			vector<tuple<int, int, int, int>> vec;
			while (!채점기.empty()) {
				if (pq.empty())break;
				int dnum = get<2>(pq.top());
				if (채점중도메인[dnum]) {
					vec.push_back(pq.top());
					pq.pop();
					continue;
				}
				int b = domainhistory[dnum].second;
				int a = domainhistory[dnum].first;
				if (t < a + 3 * (b - a)) {
					vec.push_back(pq.top());
					pq.pop();
					continue;
				}
				urls[get<3>(pq.top())]=false;
				int chae = -채점기.top();
				채점기.pop();
				채점중[chae] = dnum;
				domainhistory[dnum].first = t;
				채점중도메인[dnum] = 1;
				pq.pop();
				break;
			}
			for (auto i : vec)pq.push(i);
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
			}
		}
		else {
			int t;
			cin >> t;
			cout << pq.size() << "\n";
		}
	}
	return 0;
}