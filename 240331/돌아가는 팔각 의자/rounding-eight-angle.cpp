#include <iostream>
#include <deque>//2가 오른쪽 6이 왼쪽
using namespace std;
deque<char> dq[5];
void turn(int dir,int num)
{
    if(dir==1)
    {
        char c=dq[num].back();
        dq[num].pop_back();
        dq[num].push_front(c);
    }
    else
    {
        char c=dq[num].front();
        dq[num].pop_front();
        dq[num].push_back(c);
    }
}
void dfs(int dir,int num,int r)
{
    if(r==1 && num<4)
    {
        if(dq[num][2]!=dq[num+1][6])dfs(-dir,num+1,r);
    }
    else if(r==0 && num>0)
    {
        if(dq[num][6]!=dq[num-1][2])dfs(-dir,num-1,r);
    }
    turn(dir,num);
}
int main() {
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<8;j++)
        {
            char c;
            cin>>c;
            dq[i].push_back(c);
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int num,dir;
        cin>>num>>dir;
        if(num<4)
        {
            if(dq[num][2]!=dq[num+1][6])dfs(-dir,num+1,1);
        }
        if(num>0)
        {
            if(dq[num][6]!=dq[num-1][2])dfs(-dir,num-1,0);
        }
        turn(dir,num);
    }
    int ans=0,temp=1;
    for(int i=1;i<=4;i++)
    {
        if(dq[i].front()=='1')ans+=temp;
        temp*=2;
    }
    cout<<ans;
    return 0;
}