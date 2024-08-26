#include <iostream>
#include <numeric>
using namespace std;
int main(void)
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<" "<<lcm(a,b);
}