//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int memo[1001][1001];
	int fun(string s1, string s2 , int m , int n)
	{
	    if(m==0) return n;
	    if(n==0) return m;
	    if(memo[m][n] != -1)
	        return memo[m][n];
	    if(s1[m-1]==s2[n-1]) return memo[m][n] = fun(s1,s2,m-1,n-1);
	    return memo[m][n] =  1+min(fun(s1,s2,m,n-1),fun(s1,s2,m-1,n));
	}
	int funn(string s1, string s2 , int m , int n)
	{
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0)
	            {
	                dp[i][j]=j;
	            }
	            if(j==0)
	            {
	                dp[i][j]=i;
	            }
	        }
	    }
	    for(int i=1;i<=m;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            if(s1[i-1]==s2[j-1])
	                dp[i][j]=dp[i-1][j-1];
	            else
	                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
	        }
	    }
	    return dp[m][n];
	}
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    memset(memo,-1,sizeof(memo));
	    return funn( s1, s2 , s1.size() , s2.size());
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends