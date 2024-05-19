#include <iostream>
#include <vector>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int n,m,t,ans=0;
int room[50][50];
int nextroom[50][50];
vector<int> typhoon;
void spread()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            nextroom[i][j]+=room[i][j];
            for(int k=0;k<4;k++)
            {
                int nextx=i+dx[k];
                int nexty=j+dy[k];
                if(nextx>=0 && nextx<n && nexty>=0 && nexty<m)
                {
                    if((nextx!=typhoon[0] && nextx!=typhoon[1]) || nexty!=0)
                    {
                        nextroom[nextx][nexty]+=room[i][j]/5;
                        nextroom[i][j]-=room[i][j]/5;
                    }
                }
            }
        }
    }
}
void clean()
{
    for(int i=typhoon[0]-2;i>=0;i--)nextroom[i+1][0]=nextroom[i][0];
    for(int j=1;j<m;j++)nextroom[0][j-1]=nextroom[0][j];
    for(int i=1;i<=typhoon[0];i++)nextroom[i-1][m-1]=nextroom[i][m-1];
    for(int j=m-2;j>0;j--)nextroom[typhoon[0]][j+1]=nextroom[typhoon[0]][j];
    nextroom[typhoon[0]][1]=0;

    for(int i=typhoon[1]+2;i<n;i++)nextroom[i-1][0]=nextroom[i][0];
    for(int j=1;j<m;j++)nextroom[n-1][j-1]=nextroom[n-1][j];
    for(int i=n-2;i>=typhoon[1];i--)nextroom[i+1][m-1]=nextroom[i][m-1];
    for(int j=m-2;j>0;j--)nextroom[typhoon[1]][j+1]=nextroom[typhoon[1]][j];
    nextroom[typhoon[1]][1]=0;
}
int main() {
    cin>>n>>m>>t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>room[i][j];
            if(room[i][j]==-1)typhoon.push_back(i);
        }
    }
    for(int sec=1;sec<=t;sec++)
    {
        spread();
        clean();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                room[i][j]=nextroom[i][j];
                nextroom[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans+=room[i][j];
        }
    }
    cout<<ans+2;
    return 0;
}