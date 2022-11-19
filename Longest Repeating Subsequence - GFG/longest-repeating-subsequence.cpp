//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int lps(string s1 , string s2 , int n1 , int n2)
	    {
	        int dp[n1+1][n2+1];
	        for(int i=0;i<=n1;i++)
	        {
	            for(int j=0;j<=n2;j++)
	            {
	                if(i==0 || j==0)
	                {
	                    dp[i][j]=0;
	                }
	            }
	        }
	        for(int i=1;i<=n1;i++)
	        {
	            for(int j=1;j<=n2;j++)
	            {
	                if(s1[i-1]==s2[j-1] && i!=j)
	                {
	                    dp[i][j]=1+dp[i-1][j-1];
	                }
	                else
	                {
	                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	                }
	            }
	        }
	        return dp[n1][n2];
	    }
		int LongestRepeatingSubsequence(string str)
		{
		    string s = str;
		    int n = s.size();
		    return lps(s,str,n,n);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends