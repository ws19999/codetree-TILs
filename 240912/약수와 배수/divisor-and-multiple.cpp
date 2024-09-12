#include <iostream>
using namespace std;

int main() {
    int n,table[100],k,약수=0,배수=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>table[i];
    cin>>k;
    for(int i=0;i<n;i++)
    {
        if(k%table[i]==0)약수+=table[i];
        if(table[i]%k==0)배수+=table[i];
    }
    cout<<약수<<"\n"<<배수;
    return 0;
}