//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101] , int node , int col , int n , vector<int> color)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=node && graph[node][i] && color[i]==col)
            {
                return 0;
            }
        }
        return 1;
    }
    bool fun(int node , vector<int> color , bool graph[101][101] , int m , int n)
    {
        if(node==n)
        {
            return 1;
        }
        for(int col=1;col<=m;col++)
        {
            if(isSafe(graph,node,col,n,color))
            {
                color[node]=col;
                if(fun(node+1,color,graph,m,n))
                {
                    return 1;
                }
                // Backtrack
                color[node]=0;
            }
        }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) 
    {
        // int color[n] = {0};
        vector<int> color(n,0);
        return fun(0,color,graph,m,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends