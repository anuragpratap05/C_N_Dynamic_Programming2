# C_N_Dynamic_Programming2
#include<bits/stdc++.h>
using namespace std;


int knapsnack(int* val,int* wt,int W,int n){
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[W+1];
	}

	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int w=1;w<=W;w++){

			dp[i][w] = dp[i-1][w];
			if(wt[i-1] <= w){
				dp[i][w] = max(dp[i][w],val[i-1] + dp[i-1][w-wt[i-1]]);
			}
		}
	}
	/*for(int i=0;i<=n;i++)
	{
	    for(int j=0;j<=W;j++)
	    {
	        cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}
	//cout<<endl;*/
	
	
    
	int ans = dp[n][W];
    for(int i=0;i<=W;i++)
    {
        if(dp[n][i]==ans)
        {
            cout<<i<<" ";
            break;
        }
    }
	
	 
	return ans;
}
int main(){
	
	/*int val[] = {3,8,9,6,2,9,4,4,8,9};
	int wt[] = {12,15,16,16,10,21,18,12,17,18};

	int W = 50;
	int n = 10;
    cout<<endl;*/
    
    int W,n;
    cin>>W>>n;
    do
    {
        int fees_sum=0;
        int *wt=new int[n];
        int *val=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>wt[i]>>val[i];
        }
        
        cout << knapsnack(val,wt,W,n)<<endl;
        //int fun_sum=party(fees,fun,n,M,&fees_sum);
        //cout<<fees_sum<<" "<<fun_sum<<endl;
        delete [] wt;
        delete [] val;
        cin>>W>>n;
    }while(W!=0 && n!=0 );
	
}
