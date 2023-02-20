//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define ppi pair<int,pair<int,int>>
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0 , {source.first , source.second}});
        
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[source.first][source.second]=0;
        
        while(!pq.empty())
        {
            ppi p = pq.top();
            int dis = p.first;
            int i = p.second.first;
            int j = p.second.second;
            pq.pop();
            if(i-1>=0 && grid[i-1][j]==1 && dist[i-1][j]>dist[i][j]+1)
            {
                dist[i-1][j]=1+dist[i][j];
                pq.push({dist[i-1][j] , {i-1,j}});
            }
            if(j-1>=0 && grid[i][j-1]==1 && dist[i][j-1]>dist[i][j]+1)
            {
                dist[i][j-1]=1+dist[i][j];
                pq.push({dist[i][j-1] , {i,j-1}});
            }
            if(i+1<m && grid[i+1][j]==1 && dist[i+1][j]>dist[i][j]+1)
            {
                dist[i+1][j]=1+dist[i][j];
                pq.push({dist[i+1][j] , {i+1,j}});
            }
            if(j+1<n && grid[i][j+1]==1 && dist[i][j+1]>dist[i][j]+1)
            {
                dist[i][j+1]=1+dist[i][j];
                pq.push({dist[i][j+1] , {i,j+1}});
            }
        }
        if(dist[destination.first][destination.second] == 1e9)
        {
            return -1;
        }
        return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends