//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        int graph[N][N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==j)
                {
                    graph[i][j]=0;
                }
                else
                {
                    graph[i][j]=1e9;
                }
            }
        }
        for(auto it : edges)
        {
            graph[it[0]][it[1]]=it[2];
        }
        for(int k=0;k<N;k++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    graph[i][j]=min(graph[i][j] , graph[i][k]+graph[k][j]);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<N;i++)
        {
            if(graph[0][i]==1e9)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(graph[0][i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends