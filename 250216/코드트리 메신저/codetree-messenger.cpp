#include <iostream>
#include <deque>
using namespace std;
struct node {
    deque<int> sons;
    int power=0,father=-1;
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
int dfs(int depth, int num) {
    int ans = 0;
    if (depth && depth <= table[num].power)ans++;
    for (auto i : table[num].sons) {
        if(table[i].enabled)ans+=dfs(depth + 1, i);
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q;
    cin >> N>>Q;
    while (Q--) {
        int q,c;
        cin >> q;
        if (q == 100) {
            init();
        }
        else if (q == 200) {
            cin >> c;
            table[c].enabled = !table[c].enabled;
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
            for (int i = 0; i < 2; i++) {
                if (table[f1].sons[i] == c1)table[f1].sons[i] = c2;
                if (table[f2].sons[i] == c2)table[f2].sons[i] = c1;
            }
            table[c1].father = f2;
            table[c2].father = f1;
        }
        else if (q == 500) {
            cin >> c;
            cout<<dfs(0,c)<<"\n";
        }
    }
    return 0;
}