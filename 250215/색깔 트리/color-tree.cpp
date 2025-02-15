#include <iostream>
#include <vector>
#include <deque>
using namespace std;
struct node {
	vector<int> children;
	int maxdepth=101, color=0, father=0;
};
node table[100001];

void add() {
	int mid, pid, color, maxdepth;
	cin >> mid >> pid >> color >> maxdepth;
	if (pid == -1)pid = 0;
	int depth = 2, pos = pid;
	bool p = true;
	while (pos != 0) {
		if (table[pos].maxdepth < depth) {
			p = false;
			break;
		}
		pos = table[pos].father;
	}
	if (p) {
		table[pid].children.push_back(mid);
		table[mid].father = pid;
		table[mid].color = color;
		table[mid].maxdepth = maxdepth;
	}
}
void color_change() {
	int mid, color;
	cin >> mid >> color;
	deque<int> dq;
	dq.push_back(mid);
	while (!dq.empty()) {
		int nd = dq.front();
		dq.pop_front();
		table[nd].color = color;
		for (auto i : table[nd].children) {
			dq.push_back(i);
		}
	}
}
long long ans = 0;
vector<int> cal_value(int num) {
	vector<int> vals = { 0,0,0,0,0,0 };
	for (auto i : table[num].children) {
		vector<int> temp=cal_value(i);
		if (num != 0) {
			for (int i = 1; i <= 5; i++)vals[i] += temp[i];
		}
	}
	vals[table[num].color]++;
	if (num != 0) {
		int cnt = 0;
		for (int i = 1; i <= 5; i++)if (vals[i])cnt++;
		ans += cnt * cnt;
	}
	return vals;
}
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q;
	cin >> Q;
	for (int query = 0; query < Q; query++)
	{
		int q;
		cin >> q;
		if (q == 100)add();
		else if (q == 200)color_change();
		else if (q == 300) {
			int mid;
			cin >> mid;
			cout << table[mid].color << "\n";
		}
		else if (q == 400) {
			ans = 0;
			cal_value(0);
			cout << ans << "\n";
		}
	}
	return 0;
}