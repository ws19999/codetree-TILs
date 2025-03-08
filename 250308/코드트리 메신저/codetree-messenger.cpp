#include <iostream>
#include <deque>
using namespace std;
struct node {
	int father, noti[20] = { 0 },power=0;
	bool on = true;
};
node table[100001];
void change(int c, int type) {
	deque<int> dq;
	int sz = 19;
	for (int i = 0; i <= 19; i++)dq.push_back(table[c].noti[i]);
	while (table[c].on) {
		dq.pop_front();
		c = table[c].father;
		if (c == -1)break;
		sz--;
		for (int i = 0; i <= sz; i++) table[c].noti[i] += dq[i] * type;
	}
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, Q;
	cin >> N >> Q;
	table[0].father = -1;
	for (int query = 1; query <= Q; query++) {
		int q;
		cin >> q;
		if (q == 100) {
			for (int i = 1; i <= N; i++) {
				int p;
				cin >> p;
				table[i].father = p;
			}
			for (int i = 1; i <= N; i++) {
				int a;
				cin >> a;
				if (a >= 20)a = 19;
				table[i].noti[a] = 1;
				table[i].power = a;
			}
			for (int i = 1; i <= N; i++) {
				int power = table[i].power;
				int pos = i;
				while (pos) {
					pos = table[pos].father;
					--power;
					if (power<0)break;
					table[pos].noti[power]++;
				}
			}
		}
		else if (q == 200) {
			int c;
			cin >> c;
			if (table[c].on) {
				change(c, -1);
				table[c].on = false;
			}
			else {
				table[c].on = true;
				change(c, 1);
			}
		}
		else if (q == 300) {
			int c, power;
			cin >> c >> power;
			if (power >= 20)power = 19;
			int pos = c;
			int p = table[c].power;
			table[c].noti[p]--;
			while (table[pos].on) {
				pos = table[pos].father;
				if (pos == -1)break;
				--p;
				if (p < 0)break;
				table[pos].noti[p]--;
			}
			pos = c;
			table[c].power = power;
			table[c].noti[power]++;
			while (table[pos].on) {
				pos = table[pos].father;
				if (pos == -1)break;
				--power;
				if (power < 0)break;
				table[pos].noti[power]++;
			}
		}
		else if (q == 400) {
			int c1, c2;
			cin >> c1 >> c2;
			if (table[c1].father == table[c2].father)continue;
			int f1 = table[c1].father;
			int f2 = table[c2].father;
			change(c1, -1);
			table[c1].father = f2;
			change(c1, 1);
			change(c2, -1);
			table[c2].father = f1;
			change(c2, 1);
		}
		else if (q == 500) {
			int c,ans=-1;
			cin >> c;
			for (int i = 0; i <= 19; i++)ans += table[c].noti[i];
			cout << ans << "\n";
		}
	}
	return 0;
}
