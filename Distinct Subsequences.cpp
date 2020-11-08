# C_N_Dynamic_Programming2
#include<bits/stdc++.h>
using namespace std;

long long subsequences(string s,long long n)
{
    vector<long long> last(256,-1);
    
    long long dp[n+1];
    dp[0]=1;
    
    for(long long i=1;i<=n;i++)
    {
        dp[i]=2*(dp[i-1]%1000000007);
        
        if(last[s[i-1]]!=-1)
        {
            dp[i]=(dp[i]-dp[last[s[i-1]]]+1000000007)%1000000007;
        }
        
        last[s[i-1]]=(i-1);
    }
    return dp[n]%1000000007;
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
    string s;
    cin>>s;
    
    long long n=s.length();
    cout<<subsequences(s,n)<<endl;
    }
}
