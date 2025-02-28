#include <iostream>
#include <deque>
using namespace std;
struct node {
    deque<int> sons;
    int power = 0, father = -1;
    bool enabled = true;
};
node table[100001];
int N;
void init() {
    for (int i = 1; i <= N; i++) {
        cin >> table[i].father;
        table[table[i].father].sons.push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> table[i].power;
    }
}
int bfs(int o) {
    int ans = -1;
    deque<pair<int,int>> dq;
    dq.push_back(make_pair(o,0));
    while (!dq.empty()) {
        int num = dq.front().first;
        int depth = dq.front().second;
        dq.pop_front();
        if (depth <= table[num].power)ans++;
        for (auto i : table[num].sons) {
            if(table[i].enabled)dq.push_back(make_pair(i,depth+1));
        }
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q;
    cin >> N >> Q;
    while (Q--) {
        int q, c;
        cin >> q;
        if (q == 100) {
            init();
        }
        else if (q == 200) {
            cin >> c;
            if (table[c].enabled)table[c].enabled = false;
            else table[c].enabled = true;
        }
        else if (q == 300) {
            cin >> c;
            cin >> table[c].power;
        }
        else if (q == 400) {
            int c1, c2;
            cin >> c1 >> c2;
            int f1 = table[c1].father;
            int f2 = table[c2].father;
            if (f1 == f2)continue;
            for (int i = 0; i < table[f1].sons.size(); i++) {
                if (table[f1].sons[i] == c1)table[f1].sons[i] = c2;
            }
            for (int i = 0; i < table[f2].sons.size(); i++) {
                if (table[f2].sons[i] == c2)table[f2].sons[i] = c1;
            }
            table[c1].father = f2;
            table[c2].father = f1;
        }
        else if (q == 500) {
            cin >> c;
            cout << bfs(c) << "\n";
        }
    }
    return 0;
}
