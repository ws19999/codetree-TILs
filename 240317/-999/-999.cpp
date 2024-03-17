#include <iostream>
using namespace std;
int main() {
    int Max=-999,Min=999;
    while(true)
    {
        int num;
        cin>>num;
        if(num==-999)break;
        Max=max(Max,num);
        Min=min(Min,num);
    }
    cout<<Max<<" "<<Min;
    return 0;
}