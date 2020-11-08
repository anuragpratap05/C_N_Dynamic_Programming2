# C_N_Dynamic_Programming2
#include<bits/stdc++.h>
using namespace std;

int help(int n, int open , int close,bool temp[],int dp[][100])
{
    
    if(open>n or close>n)
    {
        return 0;
    }
    
    if(open ==n and close ==n)
    {
        return 1;
    }
    
    if(dp[open][close]!=-1)
    {
        return  dp[open][close];
    }
    
    if(open==close or temp[open+close]==true)
    {
        return dp[open][close]= help(n, open+1,close,temp,dp);
    }
    else if(open==n)
    {
        return dp[open][close]= help(n,open,close+1,temp,dp);
    }
    
    else
    {
        return dp[open][close]= (help(n, open+1,close,temp,dp)+help(n,open,close+1,temp,dp));
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    
    bool temp[2*n];
    
    for(int i=0;i<2*n;i++)
    {
        temp[i]=false;
    }
    
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        temp[x-1]=true;
    }
    int dp[100][100];
    
    memset(dp,-1,sizeof(dp));
    
    
    
    //char out[10000];
    
    /*for(int i=0;i<2*n;i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;*/
    
    cout<<help(n,0,0,temp,dp)<<endl;
    }
}
