#include <iostream>
#include <deque>
using namespace std;
int dx[]={0,0,0,-1,1};
int dy[]={0,1,-1,0,0};
typedef struct horse
{
    int dir,num;
}Horse;
pair<int,int> horses[11];
deque<Horse> table[13][13];
int colors[14][14];
int N,K;
int changedir(int num)
{
    if(num==1)return 2;
    else if(num==2)return 1;
    else if(num==3)return 4;
    else if(num==4)return 3;
}
bool go()
{
    for(int h=1;h<=K;h++)
    {
        int x=horses[h].first;
        int y=horses[h].second;
        int pos=0;
        while(table[x][y][pos].num!=h)pos++;
        int nextx=x+dx[table[x][y][pos].dir];
        int nexty=y+dy[table[x][y][pos].dir];
        if(nextx>N || nextx<=0 || nexty>N || nexty<=0 || colors[nextx][nexty]==2)
        {
            table[x][y][pos].dir=changedir(table[x][y][pos].dir);
            nextx=x+dx[table[x][y][pos].dir];
            nexty=y+dy[table[x][y][pos].dir];
            if(nextx>N || nextx<=0 || nexty>N || nexty<=0 || colors[nextx][nexty]==2)continue;
        }
        if(colors[nextx][nexty]==0)
        {
            for(int i=pos;i>=0;i--)
            {
                table[nextx][nexty].push_front(table[x][y][i]);
                horses[table[x][y][i].num].first=nextx;
                horses[table[x][y][i].num].second=nexty;
            }
            for(int i=0;i<=pos;i++)table[x][y].pop_front();
        }
        else
        {
            for(int i=0;i<=pos;i++)
            {
                table[nextx][nexty].push_front(table[x][y].front());
                horses[table[x][y].front().num].first=nextx;
                horses[table[x][y].front().num].second=nexty;
                table[x][y].pop_front();
            }
        }
        if(table[nextx][nexty].size()>=4)return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>colors[i][j];
        }
    }
    for(int i=1;i<=K;i++)
    {
        Horse h;
        cin>>horses[i].first>>horses[i].second>>h.dir;
        h.num=i;
        table[horses[i].first][horses[i].second].push_back(h);
    }
    for(int turn=1;turn<=1000;turn++)
    {
        if(go())
        {
            cout<<turn;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}