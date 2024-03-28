#include <iostream>
using namespace std;
int block[100][100];
int map[100][100];
int main() {
    int n,ans=0,l;
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        bool possible=true;
        for(int j=0;j<n-1;j++)
        {
            if(block[i][j]==1 && map[i][j+1]==map[i][j])continue;
            if(map[i][j]==map[i][j+1])continue;
            if(map[i][j]==map[i][j+1]+1)
            {
                if(j+l>=n)
                {
                    possible=false;
                    break;
                }
                block[i][j+1]=1;
                for(int k=j+2;k<=j+l;k++)
                {   
                    if(map[i][k]==map[i][k-1])
                    {
                        block[i][k]=1;
                    }
                    else{
                        possible=false;
                        break;
                    }
                }
            }
            else if(map[i][j]==map[i][j+1]-1)
            {
                if(j-l<-1)
                {
                    possible=false;
                    break;
                }
                if(block[i][j]==1)
                {
                    possible=false;
                    break;
                }
                block[i][j]=1;
                for(int k=j-1;k>j-l;k--)
                {
                    if(block[i][k]==1)
                    {
                        possible=false;
                        break;
                    }
                    block[i][k]=1;
                }
            }
            else
            {
                possible=false;
                break;
            }
        }
        if(possible)
        {
            //cout<<i<<"\n";
            ans++;
        }
    }


    for(int j=0;j<n;j++)
    {
        bool possible=true;
        for(int i=0;i<n-1;i++)
        {
            if(block[i][j]==2 && map[i+1][j]==map[i][j])continue;
            if(map[i][j]==map[i+1][j])continue;
            if(map[i][j]==map[i+1][j]+1)
            {
                if(i+l>=n)
                {
                    possible=false;
                    break;
                }
                block[i+1][j]=2;
                for(int k=i+2;k<=i+l;k++)
                {   
                    if(map[k][j]==map[k-1][j])
                    {
                        block[k][j]=2;
                    }
                    else{
                        possible=false;
                        break;
                    }
                }
            }
            else if(map[i][j]==map[i+1][j]-1)
            {
                if(i-l<-1)
                {
                    possible=false;
                    break;
                }
                if(block[i][j]==2)
                {
                    possible=false;
                    break;
                }
                block[i][j]=2;
                for(int k=i-1;k>i-l;k--)
                {
                    if(block[k][j]==2)
                    {
                        possible=false;
                        break;
                    }
                    block[k][j]=2;
                }
            }
            else
            {
                possible=false;
                break;
            }
        }
        if(possible)
        {
            //cout<<j<<"\n";
            ans++;
        }
    }
    cout<<ans;
    return 0;
}