//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define ppi pair<int,pair<int,int>>
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) 
    {
        
        if(A[0][0]==0 || A[X][Y]==0)
        {
            return -1;
        }
        
        int m=A.size();
        int n=A[0].size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0 , {0 , 0}});
        
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        
        while(!pq.empty())
        {
            ppi p = pq.top();
            int dis = p.first;
            int i = p.second.first;
            int j = p.second.second;
            pq.pop();
            if(i-1>=0 && A[i-1][j]==1 && dist[i-1][j]>dist[i][j]+1)
            {
                dist[i-1][j]=1+dist[i][j];
                pq.push({dist[i-1][j] , {i-1,j}});
            }
            if(j-1>=0 && A[i][j-1]==1 && dist[i][j-1]>dist[i][j]+1)
            {
                dist[i][j-1]=1+dist[i][j];
                pq.push({dist[i][j-1] , {i,j-1}});
            }
            if(i+1<m && A[i+1][j]==1 && dist[i+1][j]>dist[i][j]+1)
            {
                dist[i+1][j]=1+dist[i][j];
                pq.push({dist[i+1][j] , {i+1,j}});
            }
            if(j+1<n && A[i][j+1]==1 && dist[i][j+1]>dist[i][j]+1)
            {
                dist[i][j+1]=1+dist[i][j];
                pq.push({dist[i][j+1] , {i,j+1}});
            }
        }
        if(dist[X][Y] == 1e9)
        {
            return -1;
        }
        return dist[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends