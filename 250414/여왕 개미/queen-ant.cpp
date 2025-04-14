#include <iostream>
#include <climits>
#include <set>
using namespace std;
int house[30001];
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q,minn=INT_MAX,maxx=-INT_MAX,N,housecnt=0,p,q;
    cin >> Q;
    set<int> s;
    multiset<int> dist;
    while (Q--) {
        int dir;
        cin >> dir;
        if (dir == 100) {
            cin >> N;
            housecnt = N;
            for (int i = 1; i <= N; i++) {
                int x;
                cin >> x;
                house[i] = x;
                minn = min(x, minn);
                maxx = max(x, maxx);
                s.insert(x);
            }
            auto it = s.begin();
            while (true) {
                int a = (*it);
                it++;
                if (it == s.end())break;
                int b = (*it);
                dist.insert(b - a);
            }
        }
        else if (dir == 200) {
            housecnt++;
            N++;
            int p;
            cin >> p;
            house[N] = p;
            s.insert(p);
            if (housecnt == 1) {
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
                auto it = s.lower_bound(p);
                it--;
                int a = (*it);
                it++;
                it++;
                int b = (*it);
                auto itt = dist.find(b - a);
                dist.erase(itt);
                dist.insert(p - a);
                dist.insert(b - p);
            }
            
        }
        else if (dir == 300) {
            housecnt--;
            cin >> q;
            auto it = s.lower_bound(house[q]);
            s.erase(it++);
            if (housecnt == 0) {
                maxx = -INT_MIN;
                minn = INT_MAX;
                continue;
            }
            if (house[q] == minn) {
                it = s.begin();
                auto itt = dist.find((*it) - minn);
                dist.erase(itt);
                minn = (*(it));
            }
            else if (house[q] == maxx) {
                it = s.end();
                it--;
                auto itt = dist.find(maxx - (*it));
                dist.erase(itt);
                maxx = (*it);
            }
            else {
                int b = (*it);
                it--;
                int a = (*it);
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
            if (r >= housecnt)cout << 0 << "\n";
            else if (r == 1) {
                cout << maxx - minn << "\n";
            }
            else {
                auto it = dist.begin();
                int temp=housecnt - r;
                int ans = 0;
                for(int cnt=0;cnt<=temp;cnt++) {
                    ans += (*it);
                    it++;
                }
                cout << ans<<"\n";
            }
        }
       
    }
    return 0;
}