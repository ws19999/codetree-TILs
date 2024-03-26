#include <iostream>
#include <deque>
using namespace std;
int map[8][8];
int tempmap[8][8];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int main() {
    int n,m,wallcnt=3,firecnt=0,mapsize,ans=0;
    cin>>n>>m;
    mapsize=n*m;
    deque<pair<int,int>>fire;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==1)wallcnt++;
            else if(map[i][j]==2)
            {
                firecnt++;
                fire.push_back(make_pair(i,j));
            }
        }
    }
    deque<pair<int,int>> dq;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j])continue;
            map[i][j]=1;
            for(int k=0;k<n;k++)
            {
                for(int l=0;l<m;l++)
                {
                    if(map[k][l])continue;
                    map[k][l]=1;
                    for(int o=0;o<n;o++)
                    {
                        for(int p=0;p<m;p++)
                        {
                            if(map[o][p])continue;
                            map[o][p]=1;
                            for(int q=0;q<n;q++)
                            {
                                for(int r=0;r<m;r++)
                                {
                                    tempmap[q][r]=map[q][r];
                                }
                            }
                            for(auto s:fire)dq.push_back(s);
                            int tempfire=firecnt;
                            while(!dq.empty())
                            {
                                int x=dq.front().first;
                                int y=dq.front().second;
                                dq.pop_front();
                                for(int q=0;q<4;q++)
                                {
                                    int nextx=x+dx[q];
                                    int nexty=y+dy[q];
                                    if(nextx>=n || nextx<0 || nexty<0 || nexty>=m)continue;
                                    if(tempmap[nextx][nexty])continue;
                                    tempmap[nextx][nexty]=1;
                                    tempfire++;
                                    dq.push_back(make_pair(nextx,nexty));
                                }
                            }
                            ans=max(ans,mapsize-tempfire-wallcnt);
                            map[o][p]=0;
                        }
                    }
                    map[k][l]=0;
                }
            }
            map[i][j]=0;
        }
    }
    cout<<ans;
    return 0;
}