//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  
	{
	    int tot_sum=0;
	    for(auto i=0;i<n;i++)
	    {
	        tot_sum+=arr[i];
	    }
	    bool dp[n+1][tot_sum+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=1;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=tot_sum;j++)
	        {
	            if(arr[i-1] > j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	        }
	    }
	    int sum1,sum2;
	    int ans=tot_sum;
	    for(int i=0;i<=tot_sum;i++)
	    {
	        if(dp[n][i])
	        {
	            sum1=i;
	            sum2=tot_sum-i;
	            ans=min(ans,abs(sum1-sum2));
	        }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends