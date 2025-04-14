#include <iostream>
#include <climits>
#include <set>
using namespace std;
int house[30001];
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q,minn=INT_MAX,maxx=-INT_MAX,N,houses=0;
    cin >> Q;
    set<pair<int,int>> s;
    multiset<int> dist;
    while (Q--) {
        int dir;
        cin >> dir;
        if (dir == 100) {
            cin >> N;
            houses = N;
            for (int i = 1; i <= N; i++) {
                int x;
                cin >> x;
                house[i] = x;
                minn = min(x, minn);
                maxx = max(x, maxx);
                s.insert(make_pair(x, i));
            }
            auto it = s.begin();
            while (true) {
                int a = (*it).first;
                it++;
                if (it == s.end())break;
                int b = (*it).first;
                dist.insert(b - a);
            }
        }
        else if (dir == 200) {
            houses++;
            N++;
            int p;
            cin >> p;
            house[N] = p;
            s.insert(make_pair(p, N));
            if (houses == 1) {
                maxx = p;
                minn = p;
                continue;
            }
            if (p > maxx)
            {
                dist.insert(p-maxx);
                maxx = p;
            }
            else if (p < minn) {
                dist.insert(minn - p);
                minn = p;
            }
            else {
                auto it = s.lower_bound(make_pair(p, 0));
                it--;
                int a = (*it).first;
                it++;
                it++;
                int b = (*it).first;
                dist.erase(b - a);
                dist.insert(p - a);
                dist.insert(b - p);
            }
            
        }
        else if (dir == 300) {
            houses--;
            int q;
            cin >> q;
            auto it = s.lower_bound(make_pair(house[q], 0));
            s.erase(it++);
            if (houses == 0) {
                maxx = -INT_MIN;
                minn = INT_MAX;
                continue;
            }
            if (house[q] == minn) {
                it = s.begin();
                auto itt = dist.find((*it).first - minn);
                dist.erase(itt);
                minn = (*(it)).first;
            }
            else if (house[q] == maxx) {
                it = s.end();
                it--;
                auto itt = dist.find(maxx - (*it).first);
                dist.erase(itt);
                maxx = (*it).first;
            }
            else {
                
                int b = (*it).first;
                it--;
                int a = (*it).first;
                auto itt = dist.find(b - house[q]);
                dist.erase(itt);
                itt = dist.find(house[q] - a);
                dist.erase(itt);
                dist.insert(b - a);
            }
        }
        else {
            int r;
            cin >> r;
            if (r >= houses)cout << 0 << "\n";
            else if (r == 1) {
                cout << maxx - minn << "\n";
            }
            else {
                auto it = dist.begin();
                int temp=houses - r;
                int cnt = 0;
                int ans = 0;
                while (it != dist.end()) {
                    cnt++;
                    ans += (*it);
                    it++;
                    if (cnt == temp)break;
                }
                cout << ans<<"\n";
            }
        }
       
    }
    return 0;
}