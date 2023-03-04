//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) 
    {
        int mod=1e9+7;
        m=grid.size();
        n=grid[0].size();
        int dp[m][n];
        if(grid[0][0]==1)
        {
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<m;i++)
        {
            if(grid[i][0]==1)
            {
                dp[i][0]=0;
            }
            else
            {
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int i=1;i<n;i++)
        {
            if(grid[0][i]==1)
            {
                dp[0][i]=0;
            }
            else
            {
                dp[0][i]=dp[0][i-1];
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                }
            }
        }
        return dp[m-1][n-1]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends