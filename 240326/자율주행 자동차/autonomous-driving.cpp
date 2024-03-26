#include <iostream>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int map[50][50];
bool visit[50][50];
int main() {
    int n,m;
    int visited=1;
    cin>>n>>m;
    int x,y,dir;
    cin>>x>>y>>dir;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
    visit[x][y]=true;
    while(true)
    {
        bool move=false;
        for(int i=0;i<4;i++)
        {
            dir=(dir+3)%4;
            int nextx=x+dx[dir];
            int nexty=y+dy[dir];
            if(!map[nextx][nexty] && !visit[nextx][nexty])
            {
                move=true;
                x=nextx;
                y=nexty;
                visited++;
                visit[x][y]=true;
            }
            if(move)break;
        }
        if(move)continue;
        else
        {
            x-=dx[dir];
            y-=dy[dir];
            if(map[x][y])break;
            if(!visit[x][y])visited++;
            visit[x][y]=true;
        }
    }
    cout<<visited;
    return 0;
}