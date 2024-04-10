#include <iostream>
using namespace std;
int ladder[31][11];
int n,m,h,ans=4;
void dfs(int depth)
{
    if(depth==4)return;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(!ladder[i][j] && !ladder[i][j-1])
            {
                bool possible=true;
                ladder[i][j]=1;
                for(int k=1;k<=n;k++)
                {
                    int num=k;
                    for(int l=1;l<=h;l++)
                    {
                        if(ladder[l][num-1])num--;
                        else if(ladder[l][num])num++;
                    }
                    if(k!=num)
                    {
                        possible=false;
                        break;
                    }
                }
                if(possible)
                {
                    ans=min(ans,depth);
                    ladder[i][j]=0;
                    return;
                }
                dfs(depth+1);
                ladder[i][j]=0;
            }
        }
    }
}
int main() {
    cin>>n>>m>>h;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        ladder[a][b]=1;
    }
    dfs(1);
    if(ans==4)cout<<-1;
    else cout<<ans;
    return 0;
}