#include <iostream>
using namespace std;
int map[200][200],n,m,ans=0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
bool check[200][200]={false};
void dfs(int i,int j,int sums,int depth)
{
    if(depth==4)
    {
        ans=max(ans,sums);
        return;
    }
    for(int k=0;k<4;k++)
    {
        int nextx=i+dx[k];
        int nexty=j+dy[k];
        if(nextx<0 || nextx>=n || nexty<0 || nexty>=m)continue;
        if(check[nextx][nexty])continue;
        check[nextx][nexty]=true;
        dfs(nextx,nexty,sums+map[nextx][nexty],depth+1);
        check[nextx][nexty]=false;
    }
}
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            check[i][j]=true;
            dfs(i,j,map[i][j],1);
            check[i][j]=false;
            if(i+2<n && j+1<m)ans=max(ans,map[i][j]+map[i+1][j]+map[i+2][j]+map[i+1][j+1]);
            if(i+1<n && j+2<m)ans=max(ans,map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+1]);
            if(i+2<n && j-1>0)ans=max(ans,map[i][j]+map[i+1][j]+map[i+2][j]+map[i+1][j-1]);
            if(i-1>0 && j+2<m)ans=max(ans,map[i][j]+map[i][j+1]+map[i][j+2]+map[i-1][j+1]);
        }
    }
    cout<<ans;
    return 0;
}