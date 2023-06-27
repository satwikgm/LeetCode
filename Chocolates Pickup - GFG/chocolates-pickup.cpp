//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    #define v vector
    int fun(int n , int m , vector<vector<int>>& grid , int i , int j1 , int j2 , v<v<v<int>>> &dp)
    {
        if(i<0 || i>=n || j1<0 || j1>=m || j2<0 || j2>=m)
        {
            return -1e9;
        }
        if(i==n-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }
        int ans=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int mx;
                if(j1==j2)
                {
                    mx = grid[i][j1]+fun(n,m,grid,i+1,j1+dj1,j2+dj2,dp);
                }
                else
                {
                    mx = grid[i][j1]+grid[i][j2]+fun(n,m,grid,i+1,j1+dj1,j2+dj2,dp);
                }
                ans=max(ans,mx);
            }
        }
        return dp[i][j1][j2] = ans;
    }
public:
    int solve(int n, int m, vector<vector<int>>& grid) 
    {
        v<v<v<int>>> dp(n , v<v<int>> ( m,v<int>(m,-1)));
        return fun(n,m,grid,0,0,m-1,dp);
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends