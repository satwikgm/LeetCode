//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool vis[6][6];
    void fun(int i , int j , string v , vector<string> &ans , vector<vector<int>> &m , int n)
    {
        if(i>=n || j>=n || i<0 || j<0)
        {
            return;
        }
        if(i==n-1 && j==n-1)
        {
            ans.push_back(v);
            return;
        }
        // Up
        if(i-1 >= 0 && m[i-1][j]==1 && !vis[i-1][j])
        {
            v += "U";
            vis[i-1][j]=1;
            fun(i-1,j,v,ans,m,n);
            v.pop_back();
            vis[i-1][j]=0;
        }
        // Down
        if(i+1 < n && m[i+1][j]==1 && !vis[i+1][j])
        {
            v += "D";
            vis[i+1][j]=1;
            fun(i+1,j,v,ans,m,n);
            v.pop_back();
            vis[i+1][j]=0;
        }
        // Left
        if(j-1 >= 0 && m[i][j-1]==1 && !vis[i][j-1])
        {
            v += "L";
            vis[i][j-1]=1;
            fun(i,j-1,v,ans,m,n);
            v.pop_back();
            vis[i][j-1]=0;
        }
        // Right
        if(j+1 < n && m[i][j+1]==1 && !vis[i][j+1])
        {
            v += "R";
            vis[i][j+1]=1;
            fun(i,j+1,v,ans,m,n);
            v.pop_back();
            vis[i][j+1]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        memset(vis,0,sizeof(vis));
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0)
        {
            return ans;
        }
        string v;
        vis[0][0]=1;
        fun(0,0,v,ans,m,n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends