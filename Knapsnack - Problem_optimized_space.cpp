# C_N_Dynamic_Programming2
#include<bits/stdc++.h>
int KnapSack(int val[], int wt[], int n, int W)
{
    int dp[2][W+1];
    memset(dp, 0, sizeof(dp));
    
    int i=0;
    while(i<n)
    {
        int j=0;
        while(j<=W)
        {
            if(i%2==0)
            {
                if(j>=wt[i])
                {
                    dp[1][j]=max(dp[0][j],val[i]+dp[0][j-wt[i]]);
                }
                else
                {
                    dp[1][j]=dp[0][j];
                }
                j++;
            }
            else
            {
                if(j>=wt[i])
                {
                   dp[0][j]=max(dp[1][j],val[i]+dp[1][j-wt[i]]); 
                }
                else
                {
                    dp[0][j]=dp[1][j];
                }
                j++;
            }
        }
        i++;
    }
    if(n%2==0)
    {
        return dp[0][W];
    }
    else
    {
        return dp[1][W];
    }
}

int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    
  
    
     return KnapSack(values, weights, n, maxWeight) ;


}
