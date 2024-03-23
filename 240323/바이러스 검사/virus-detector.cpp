#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,table[1000000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>table[i];
    }
    long long ans=n;
    int a,b;
    cin>>a>>b;
    for(int i=0;i<n;i++)
    {
        table[i]-=a;
        if(table[i]<=0)continue;
        ans+=table[i]/b;
        if(table[i]%b)ans++;
    }
    cout<<ans;
    return 0;
}