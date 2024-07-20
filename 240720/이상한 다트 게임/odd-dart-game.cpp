#include <iostream>
#include <deque>
#include <climits>
using namespace std;
int n,m,q,ans=0;
deque<int> table[51];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
bool changed=false;
void dfs(int x,int y)
{
    int temp=table[x][y];
    for(int k=0;k<4;k++)
    {
        int nextx=x+dx[k];
        int nexty=y+dy[k];
        if(nexty==-1)nexty=m-1;
        if (nexty == m)nexty = 0;
        if(nextx>=0 and nextx<n and nexty>=0 and nexty<m)
        {
            if(temp==table[nextx][nexty])
            {
                table[x][y]=-INT_MAX;
                dfs(nextx,nexty);
                table[nextx][nexty]=-INT_MAX;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int num;
            cin>>num;
            table[i].push_back(num);
        }
    }
    for(int i=0;i<q;i++)
    {
        int x,d,k;
        cin>>x>>d>>k;
        for(int num=x-1;num<n;num+=x)
        {
            if(d==0)
            {
                for(int a=0;a<k;a++)
                {
                    int temp=table[num].back();
                    table[num].push_front(temp);
                    table[num].pop_back();
                }
            }
            else
            {
                for(int a=0;a<k;a++)
                {
                    int temp=table[num].front();
                    table[num].push_back(temp);
                    table[num].pop_front();
                }
            }    
        }
        changed=false;
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<m;b++)
            {
                if(table[a][b]!=-INT_MAX)
                {
                    dfs(a,b);
                    if(table[a][b]==-INT_MAX)changed=true;
                }
            }
        }
        if(!changed)
        {
            int sums=0,cnt=0,avg=0;
            for(int a=0;a<n;a++)
            {
                for(int b=0;b<m;b++)
                {
                    if(table[a][b]!=-INT_MAX)
                    {
                        sums+=table[a][b];
                        cnt++;
                    }
                }
            }
            if(cnt==0)continue;
            avg=sums/cnt;
            for(int a=0;a<n;a++)
            {
                for(int b=0;b<m;b++)
                {
                    if(table[a][b]!=-INT_MAX)
                    {
                        if(table[a][b]<avg)table[a][b]++;
                        else if(table[a][b]>avg)table[a][b]--;
                    }
                }
            }
        }
    }
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<m;b++)
        {
            if(table[a][b]!=-INT_MAX)
            {
                ans+=table[a][b];
            }
        }
    }
    cout<<ans;
    return 0;
}