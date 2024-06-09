#include <iostream>
#include <deque>
#include <vector>
using namespace std;
deque<pair<int,int>> sel;
int N,M,city[50][50],ans=2500,virus=0,hospitalcnt=0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
vector<pair<int,int>> hospital;
void cal(deque<pair<int,int>> dq)
{
    deque<int> tdq;
    for(int i=0;i<M;i++)tdq.push_back(0);
    bool check[50][50]={false};
    for(auto i:dq)check[i.first][i.second]=true;
    int t,x,y,cnt=0;
    while(!tdq.empty())
    {
        x=dq.front().first;
        y=dq.front().second;
        t=tdq.front();
        dq.pop_front();
        tdq.pop_front();
        if(cnt==virus)continue;
        for(int i=0;i<4;i++)
        {
            int nextx=x+dx[i];
            int nexty=y+dy[i];
            if(nextx>=0 && nextx<N && nexty>=0 && nexty<N)
            {
                if(!city[nextx][nexty]==1 && !check[nextx][nexty])
                {
                    check[nextx][nexty]=true;
                    dq.push_back(make_pair(nextx,nexty));
                    tdq.push_back(t+1);
                    if(city[nextx][nexty]==0)cnt++;
                }
            }
        }
    }
    if(cnt==virus)ans=min(ans,t);
}
void dfs(int num,int depth)
{
    if(depth==M)
    {
        cal(sel);
        return;
    }
    for(int i=num+1;i<hospitalcnt;i++)
    {
        sel.push_back(hospital[i]);
        dfs(i,depth+1);
        sel.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>city[i][j];
            if(city[i][j]==2)
            {
                hospital.push_back(make_pair(i,j));
                hospitalcnt++;
            }
            else if(city[i][j]==0)virus++;
        }
    }
    dfs(-1,0);
    if(ans==2500)ans=-1;
    cout<<ans;
    return 0;
}