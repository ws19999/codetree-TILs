#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<pair<int,int>> human;
vector<pair<int,int>> hospital;
vector<pair<int,int>> chosen;
int n,m,hospitalcnt,ans=INT_MAX;
void choose(int cnt,int pos)
{
    if(cnt==m)
    {
        int totaldist=0;
        for(auto p:human)
        {
            int dist=INT_MAX;
            for(auto h:chosen)dist=min(dist,abs(p.first-h.first)+abs(p.second-h.second));
            totaldist+=dist;
        }
        ans=min(totaldist,ans);
        return;
    }
    for(int i=pos+1;i<hospitalcnt;i++)
    {
        chosen.push_back(hospital[i]);
        choose(cnt+1,i);
        chosen.pop_back();
    }
}
int main(void)
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            if(num==1)human.push_back(make_pair(i,j));
            else if(num==2)hospital.push_back(make_pair(i,j));
        }
    }
    hospitalcnt=hospital.size();
    choose(0,-1);
    cout<<ans;
    return 0;
}