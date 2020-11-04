#include<bits/stdc++.h>

int help(string s1, string s2, int i,int j,int dp[][1000])
{
    if(i==s1.length() or j==s2.length())
    {
        return 0;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    if(s1[i]==s2[j])
    {
        return dp[i][j]=1+help(s1,s2,i+1,j+1,dp);
    }
    int op1= help(s1,s2,i+1,j,dp);
    int op2= help(s1,s2,i,j+1,dp);
    return dp[i][j]= max(op1,op2);
}

int lcs(string s1, string s2)
{
    //Write your code here
    int dp[1000][1000];
    
    
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            dp[i][j]=-1;
        }
    }
    
    return help(s1,s2,0,0,dp);
    
}
