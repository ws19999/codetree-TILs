#include <iostream>
using namespace std;
int main() {
    int table[1001]={0};
    int N,ans=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int s,t,b;
        cin>>s>>t>>b;
        for(int j=s;j<t;j++)
        {
            table[j]+=b;
            ans=max(ans,table[j]);
        }
    }
    cout<<ans;
    return 0;
}