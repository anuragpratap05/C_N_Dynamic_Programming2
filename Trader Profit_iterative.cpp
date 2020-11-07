# C_N_Dynamic_Programming2
#include<bits/stdc++.h> 
using namespace std; 


int maxProfit(int price[],int n, int k)
{
    int dp[k+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    
    for(int i=0;i<=k;i++)
    {
        dp[i][0]=0;
    }
    
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<n;j++)
        {
            int max_so_far=INT_MIN;
            for(int m=0;m<j;m++)
            {
                max_so_far=max(max_so_far,price[j]-price[m]+dp[i-1][m]);
                
                dp[i][j]=max(dp[i][j-1],max_so_far);
            }
        }
    }
    
    /*for(int i=0;i<=k;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}*/

	return dp[k][n - 1];
}


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int n;
        cin>>n;
        int price[n];
        for(int i=0;i<n;i++)
        {
            cin>>price[i];
        }
    
	//int k = 2; 
	//int price[] = { 10, 22, 5, 75, 65, 80 }; 
	//int n = sizeof(price) / sizeof(price[0]); 

	cout <<maxProfit(price, n, k)<<endl; 
    }

	return 0; 
} 
