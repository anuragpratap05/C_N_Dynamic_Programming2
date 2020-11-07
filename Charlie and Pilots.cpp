# C_N_Dynamic_Programming2
#include<bits/stdc++.h>
using namespace std;


int help(int a[], int c[], int x,int n,int** dp)
{
    
    
    if(n==0)
    {
        return 0;
    }
    
    if(dp[n][x]!=-1)
    {
        return dp[n][x];
    }
    
    if(x==0)
    {
        return dp[n][x]= help(a+1,c+1,x+1,n-1,dp)+a[0];
    }
    if(x==n)
    {
        return dp[n][x]= help(a+1,c+1,x-1,n-1,dp)+c[0];
    }
    else
    {
        int op1=help(a+1,c+1,x-1,n-1,dp)+c[0];
        int op2= help(a+1,c+1,x+1,n-1,dp)+a[0];
        return dp[n][x]= min(op1,op2);
    }
}

int main()
{
    int n;
    cin>>n;
    
    int a[n];
    int c[n];
    for(int i=0;i<n;i++)
    {
        cin>>c[i]>>a[i];
    }
    
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[(n/2)+5];
    }
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<(n/2)+5;j++)
        {
            dp[i][j]=-1;
        }
        //cout<<endl;
    }
    
   // memset(dp,-1,sizeof(dp));
    
    /*for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    
    
    cout<<help(a,c,0,n,dp);
}
