#include <iostream>
#include <deque>
using namespace std;
int N,t=0;
typedef struct robot
{
    int lev=2,x,y,exp=0;
}Robot;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int timetable[20][20];
int table[20][20];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    Robot R;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>table[i][j];
            if(table[i][j]==9)
            {
                R.x=i;
                R.y=j;
                table[i][j]=0;
            }
        }
    }
    int phase=0,s;
    while(true)
    {
        bool possible=false;
        phase++;
        timetable[R.x][R.y]=phase;
        deque<pair<int,int>> dq;
        dq.push_back(make_pair(R.x,R.y));
        deque<int> sec;
        sec.push_back(0);
        while(!dq.empty())
        {
            int x=dq.front().first;
            int y=dq.front().second;
            s=sec.front();
            dq.pop_front();
            sec.pop_front();
            if(table[x][y] && table[x][y]<R.lev)
            {
                possible=true;
                t+=s;
                int nextx=x;
                int nexty=y;
                while(!dq.empty())
                {
                    x=dq.front().first;
                    y=dq.front().second;
                    int news=sec.front();
                    dq.pop_front();
                    sec.pop_front();
                    if(news==s && table[x][y] && table[x][y]<R.lev)
                    {
                        if(x<nextx)
                        {
                            nextx=x;
                            nexty=y;
                        }
                        else if(x==nextx && y<nexty)nexty=y;
                    }
                }
                R.x=nextx;
                R.y=nexty;
                R.exp++;
                if(R.exp==R.lev)
                {
                    R.exp=0;
                    R.lev++;
                }
                table[R.x][R.y]=0;
                break;
            }
            for(int k=0;k<4;k++)
            {
                int nextx=x+dx[k];
                int nexty=y+dy[k];
                if(nextx>=0 && nextx<N && nexty>=0 && nexty<N)
                {
                    if(timetable[nextx][nexty]<phase && table[nextx][nexty]<=R.lev)
                    {
                        timetable[nextx][nexty]=phase;
                        dq.push_back(make_pair(nextx,nexty));
                        sec.push_back(s+1);
                    }
                }
            }
        }
        if(!possible)break;
    }
    cout<<t;
    return 0;
}