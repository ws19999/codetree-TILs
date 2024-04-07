#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef struct horse
{
    int x,y,type;
}horse;
vector<horse> lists;
int n,m,len,ans=64;
int map[8][8];
int check[8][8];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void ad(int x,int y,int dir)
{
    while(x>=0 && y>=0 && x<n && y<m)
    {
        if(map[x][y]==6)return;
        check[x][y]+=1;
        x+=dx[dir];
        y+=dy[dir];
    }
}
void rem(int x,int y,int dir)
{
    while(x>=0 && y>=0 && x<n && y<m)
    {
        if(map[x][y]==6)return;
        check[x][y]-=1;
        x+=dx[dir];
        y+=dy[dir];
    }
}
void dfs(int num)
{
    if(num==len)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!check[i][j])cnt++;
            }
        }
        ans=min(cnt,ans);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int x=lists[num].x;
        int y=lists[num].y;
        if(lists[num].type==1)
        {
            ad(x+dx[i],y+dy[i],i);
            dfs(num+1);
            rem(x+dx[i],y+dy[i],i);
        }
        if(lists[num].type==2)
        {
            ad(x+dx[i],y+dy[i],i);
            ad(x+dx[(i+2)%4],y+dy[(i+2)%4],(i+2)%4);
            dfs(num+1);
            rem(x+dx[i],y+dy[i],i);
            rem(x+dx[(i+2)%4],y+dy[(i+2)%4],(i+2)%4);
        }
        if(lists[num].type==3)
        {
            ad(x+dx[i],y+dy[i],i);
            ad(x+dx[(i+1)%4],y+dy[(i+1)%4],(i+1)%4);
            dfs(num+1);
            rem(x+dx[i],y+dy[i],i);
            rem(x+dx[(i+1)%4],y+dy[(i+1)%4],(i+1)%4);
        }
        if(lists[num].type==4)
        {
            ad(x+dx[i],y+dy[i],i);
            ad(x+dx[(i+1)%4],y+dy[(i+1)%4],(i+1)%4);
            ad(x+dx[(i+2)%4],y+dy[(i+2)%4],(i+2)%4);
            dfs(num+1);
            rem(x+dx[i],y+dy[i],i);
            rem(x+dx[(i+1)%4],y+dy[(i+1)%4],(i+1)%4);
            rem(x+dx[(i+2)%4],y+dy[(i+2)%4],(i+2)%4);
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            if(map[i][j])
            {
                if(map[i][j]==6)check[i][j]=INT_MAX;
                else if(map[i][j]==5)
                {
                    check[i][j]=1;
                    for(int k=0;k<4;k++)ad(i+dx[k],j+dy[k],k);
                }
                else
                {
                    horse h;
                    h.x=i;
                    h.y=j;
                    h.type=map[i][j];
                    lists.push_back(h);
                    check[i][j]=1;
                }
            }
        }
    }
    len=lists.size();
    dfs(0);
    cout<<ans;
    return 0;
}