#include <iostream>
#include <deque>
using namespace std;
int map[101][101];
deque<int> dq;
int s=1;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
void dragoncurve(int dimansion,int endx,int endy,int maxdimansion)
{
    if(dimansion>maxdimansion)return;
    for(int i=s-1;i>=0;i--)
    {
        int next=(dq[i]+1)%4;
        dq.push_back(next);
        endx+=dx[next];
        endy+=dy[next];
        map[endx][endy]=1;
    }
    s*=2;
    dragoncurve(dimansion+1,endx,endy,maxdimansion);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        s=1;
        dq.push_back(d);
        map[x][y]=1;
        map[x+dx[d]][y+dy[d]]=1;
        dragoncurve(1,x+dx[d],y+dy[d],g);
        dq.clear();
    }
    for(int i=0;i<99;i++)
    {
        for(int j=0;j<99;j++)
        {
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])ans++;
        }
    }
    cout<<ans;
    return 0;
}