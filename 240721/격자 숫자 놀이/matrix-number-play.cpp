#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int r,c,k,maxx=3,maxy=3,table[100][100];
bool check()
{
    if(table[r][c]==k) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>r>>c>>k;
    r--;
    c--;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>table[i][j];
        }
    }
    if(check())
    {
        cout<<0;
        return 0;
    }
    for(int t=1;t<=100;t++)
    {
        if(maxx>=maxy)
        {
            int tempmaxy=0;
            for(int i=0;i<maxx;i++)
            {
                unordered_map<int,int> maps;
                for(int j=0;j<maxy;j++)
                {
                    if(table[i][j])maps[table[i][j]]++;
                }
                vector<pair<int,int>> temp;
                for(auto n:maps)
                {
                    temp.push_back(make_pair(n.second,n.first));
                }
                sort(temp.begin(),temp.end());
                int sizes=0;
                for(auto n:temp)
                {
                    table[i][sizes++]=n.second;
                    table[i][sizes++]=n.first;
                    if(sizes==100)break;
                }
                tempmaxy=max(tempmaxy,sizes);
                for(int j=sizes;j<100;j++)table[i][j]=0;
            }
            maxy=tempmaxy;
        }
        else
        {
            int tempmaxx=0;
            for(int j=0;j<maxy;j++)
            {
                unordered_map<int,int> maps;
                for(int i=0;i<maxx;i++)
                {
                    if(table[i][j])maps[table[i][j]]++;
                }
                vector<pair<int,int>> temp;
                for(auto n:maps)
                {
                    temp.push_back(make_pair(n.second,n.first));
                }
                sort(temp.begin(),temp.end());
                int sizes=0;
                for(auto n:temp)
                {
                    table[sizes++][j]=n.second;
                    table[sizes++][j]=n.first;
                    if(sizes==100)break;
                }
                tempmaxx=max(tempmaxx,sizes);
                for(int i=sizes;i<100;i++)table[i][j]=0;
            }
            maxx=tempmaxx;
        }
        if(check())
        {
            cout<<t;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}