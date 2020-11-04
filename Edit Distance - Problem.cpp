# C_N_Dynamic_Programming2
#include<bits/stdc++.h>
using namespace std;

int help(string s1, string s2,int i, int j,int n, int m,int dp[][1000] )
{
    if(n==0)
    {
        return m;
    }
    
    if(m==0)
    {
        return n;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    if(s1[i]==s2[j])
    {
        return dp[i][j]= help(s1,s2,i+1,j+1,n-1,m-1,dp);
    }
    else
    {
        int op1=1+help(s1,s2,i+1,j+1,n-1,m-1,dp);
        int op2=1+help(s1,s2,i+1,j,n-1,m,dp);
        int op3=1+help(s1,s2,i,j+1,n,m-1,dp);
        return dp[i][j]= min(min(op1,op2),op3);
    }
}

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
    int n1=s1.length();
    int n2=s2.length();
    int dp[1000][1000];
    
    
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            dp[i][j]=-1;
        }
    }
    
    return help(s1,s2,0,0,n1,n2,dp);


}

