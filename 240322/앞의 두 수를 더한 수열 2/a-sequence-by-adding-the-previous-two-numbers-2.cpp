#include <iostream>
using namespace std;
int main() {
    int table[91];
    int n;
    cin>>n;
    table[1]=1;
    table[2]=1;
    for(int i=3;i<=n;i++)table[i]=table[i-2]+table[i-1];
    cout<<table[n];
    return 0;
}