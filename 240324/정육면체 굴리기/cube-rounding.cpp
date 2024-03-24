#include <iostream>
using namespace std;
typedef struct dice
{
    int top=0,down=0,front=0,back=0,left=0,right=0,x,y;
}dice;
dice x;
int dx[]={0,0,0,-1,1};
int dy[]={0,1,-1,0,0};
int map[20][20],n,m,k;
int roll(int dir)
{
    int temp;
    if(dir==1)
    {
        temp=x.top;
        x.top=x.left;
        x.left=x.down;
        x.down=x.right;
        x.right=temp;
    }
    else if(dir==2)
    {
        temp=x.top;
        x.top=x.right;
        x.right=x.down;
        x.down=x.left;
        x.left=temp;
    }
    else if(dir==3)
    {
        temp=x.top;
        x.top=x.back;
        x.back=x.down;
        x.down=x.front;
        x.front=temp;
    }
    else if(dir==4)
    {
        temp=x.top;
        x.top=x.front;
        x.front=x.down;
        x.down=x.back;
        x.back=temp;
    }
    if(map[x.x][x.y]==0)
    {
        map[x.x][x.y]=x.down;
    }
    else
    {
        x.down=map[x.x][x.y];
        map[x.x][x.y]=0;
    }
    return x.top;
}
int main() {
    cin>>n>>m>>x.x>>x.y>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<k;i++)
    {
        int dir;
        cin>>dir;
        if(x.x+dx[dir]<0 || x.x+dx[dir]>=n || x.y+dy[dir]<0 || x.y+dy[dir]>=m)continue;
        x.x+=dx[dir];
        x.y+=dy[dir];
        cout<<roll(dir)<<"\n";
    }
    return 0;
}