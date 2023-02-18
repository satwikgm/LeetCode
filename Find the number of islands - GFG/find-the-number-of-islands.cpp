//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid , int a , int b , bool visited[501][501])
    {
        visited[a][b]=1;
        queue<pair<int,int>> q;
        q.push({a,b});
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> rowVar{-1,0,1};
        vector<int> colVar{-1,0,1};
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            visited[i][j]=1;
            for(auto it1 : rowVar)
            {
                for(auto it2 : colVar)
                {
                    int r = i+it1;
                    int c = j+it2;
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1' && !visited[r][c])
                    {
                        q.push({r,c});
                        visited[r][c]=1;
                    }
                }
            }
               
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        bool visited[501][501];
        memset(visited,0,sizeof(visited));
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(!visited[i][j])
                    {
                        ans++;
                        bfs(grid,i,j,visited);
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends