#include <iostream>
#include <climits>
using namespace std;
int table[21][21];
bool check[21];
int ans=INT_MAX,n;
void dfs(int last,int depth)
{
    if(depth==n/2)
    {
        int a=0,b=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(check[i] && check[j])a+=table[i][j];
                else if(!check[i] && !check[j])b+=table[i][j];
            }
        }
        ans=min(ans,abs(a-b));
    }
    for(int i=last+1;i<=n;i++)
    {
        if(check[i])continue;
        check[i]=true;
        dfs(i,depth+1);
        check[i]=false;
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>table[i][j];
        }
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}