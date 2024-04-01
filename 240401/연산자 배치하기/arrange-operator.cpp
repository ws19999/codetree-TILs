#include <iostream>
#include <climits>
using namespace std;
int table[11],n,ansmax=-INT_MAX,ansmin=INT_MAX;
void dfs(int num,int depth,int tb[3])
{
    if(depth==n)
    {
        ansmax=max(ansmax,num);
        ansmin=min(ansmin,num);
        return;
    }
    if(tb[0]>0)
    {
        tb[0]-=1;
        dfs(num+table[depth],depth+1,tb);
        tb[0]+=1;
    }
    if(tb[1]>0)
    {
        tb[1]-=1;
        dfs(num-table[depth],depth+1,tb);
        tb[1]+=1;
    }
    if(tb[2]>0)
    {
        tb[2]-=1;
        dfs(num*table[depth],depth+1,tb);
        tb[2]+=1;
    }
}
int main() {
    cin>>n;
    int tb[3];
    for(int i=0;i<n;i++)cin>>table[i];
    for(int i=0;i<3;i++)cin>>tb[i];
    dfs(table[0],1,tb);
    cout<<ansmin<<" "<<ansmax;
    return 0;
}