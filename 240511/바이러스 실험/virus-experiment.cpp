#include <iostream>
#include <queue>
#include <tuple>
#include <deque>
using namespace std;
int n,m,k;
int add_nutrient[10][10];
int next_nutrient[10][10]={0};
priority_queue<tuple<int,int,int>> virus;
int nutrient[10][10];
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
int main() {    
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            nutrient[i][j]=5;
            cin>>add_nutrient[i][j];
            next_nutrient[i][j]=add_nutrient[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        int r,c,age;
        cin>>r>>c>>age;
        virus.push(make_tuple(-age,r-1,c-1));
    }
    for(int tc=1;tc<=k;tc++)
    {
        priority_queue<tuple<int,int,int>> nextvirus;
        while(!virus.empty())
        {
        int age=-get<0>(virus.top());
        int x=get<1>(virus.top());
        int y=get<2>(virus.top());
        virus.pop();
        if(age<=nutrient[x][y])
        {
            nutrient[x][y]-=age;
            age++;
            if(age%5==0)
            {
                for(int k=0;k<8;k++)
                {
                    int nextx=x+dx[k];
                    int nexty=y+dy[k];
                    if(nextx>=0 && nextx<n && nexty>=0 && nexty<n)
                    {
                        nextvirus.push(make_tuple(-1,nextx,nexty));
                    }
                }
            }
            nextvirus.push(make_tuple(-age,x,y));
        }
        else
        {
            next_nutrient[x][y]+=age/2;
        }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                nutrient[i][j]+=next_nutrient[i][j];
                next_nutrient[i][j]=add_nutrient[i][j];
            }
        }
        virus=nextvirus;
    }
    cout<<virus.size();
    return 0;
}