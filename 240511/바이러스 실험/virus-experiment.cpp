#include <iostream>
#include <queue>
#include <tuple>
#include <deque>
using namespace std;
int n,m,k;
int add_nutrient[10][10];
int next_nutrient[10][10]={0};
deque<tuple<int,int,int>> virus;
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
        virus.push_back(make_tuple(-age,r-1,c-1));
    }
    for(int tc=1;tc<=k;tc++)
    {
        deque<tuple<int,int,int>> nextvirus;
        int mins=0;
        for(int i=0;i<m;i++)
        {
        int age=-get<0>(virus.front());
        int x=get<1>(virus.front());
        int y=get<2>(virus.front());
        virus.pop_front();
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
                        nextvirus.push_back(make_tuple(-1,nextx,nexty));
                    }
                }
            }
            virus.push_back(make_tuple(-age,x,y));
        }
        else
        {
            mins++;
            next_nutrient[x][y]+=age/2;
        }
        }
        while(!nextvirus.empty())
        {
            m++;
            virus.push_front(nextvirus.front());
            nextvirus.pop_front();
        }
        m-=mins;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                nutrient[i][j]+=next_nutrient[i][j];
                next_nutrient[i][j]=add_nutrient[i][j];
            }
        }
    }
    cout<<m;
    return 0;
}