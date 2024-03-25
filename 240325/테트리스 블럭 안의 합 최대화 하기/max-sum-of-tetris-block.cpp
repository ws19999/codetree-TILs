#include <iostream>
using namespace std;
int map[200][200],n,m,ans=0;
void block11(int x,int y)
{
    ans=max(ans,map[x][y]+map[x][y+1]+map[x][y+2]+map[x][y+3]);
}
void block12(int x,int y)
{
    ans=max(ans, map[x][y]+map[x+1][y]+map[x+2][y]+map[x+3][y]);
}
void block2(int x,int y)
{
    ans=max(ans,map[x][y]+map[x+1][y]+map[x][y+1]+map[x+1][y+1]);
}
void block31(int x, int y)
{
    ans=max(ans,map[x][y]+map[x][y-1]+map[x-1][y-1]+map[x-2][y-1]);
}
void block32(int x, int y)
{
    ans=max(ans,map[x][y]+map[x-1][y]+map[x-1][y+1]+map[x-1][y+2]);
}
void block33(int x, int y)
{
    ans=max(ans,map[x][y]+map[x][y+1]+map[x+1][y+1]+map[x+2][y+1]);
}
void block34(int x, int y)
{
    ans=max(ans,map[x][y]+map[x+1][y]+map[x+1][y-1]+map[x+1][y-2]);
}
void block41(int x,int y)
{
    ans=max(ans,map[x][y]+map[x+1][y]+map[x+1][y+1]+map[x+2][y+1]);
}
void block42(int x,int y)
{
    ans=max(ans,map[x][y]+map[x][y+1]+map[x-1][y+1]+map[x-1][y+2]);
}
void block51(int x,int y)
{
    ans=max(ans,map[x][y]+map[x+1][y]+map[x+2][y]+map[x+1][y+1]);
}
void block52(int x,int y)
{
    ans=max(ans,map[x][y]+map[x][y+1]+map[x][y+2]+map[x+1][y+1]);
}
void block53(int x,int y)
{
    ans=max(ans,map[x][y]+map[x+1][y]+map[x+2][y]+map[x+1][y-1]);
}
void block54(int x,int y)
{
    ans=max(ans,map[x][y]+map[x][y+1]+map[x][y+2]+map[x-1][y+1]);
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
            if(j+3<m)block11(i,j);
            if(j+3<n)block12(i,j);
            if(i+1<n && j+1<m)block2(i,j);
            if(i-2>0 && j-1>0)block31(i,j);
            if(i-1>0 && j+2<m)block32(i,j);
            if(i+2<n && j+1<m)block33(i,j);
            if(i+2<n && j-2>0)block34(i,j);
            if(i+2<n && j+1<m)block41(i,j);
            if(i-1>0 && j+2<m)block42(i,j);
            if(i+2<n && j+1<m)block51(i,j);
            if(i+1<n && j+2<m)block52(i,j);
            if(i+2<n && j-1>0)block53(i,j);
            if(i-1>0 && j+2<m)block54(i,j);
        }
    }
    cout<<ans;
    return 0;
}