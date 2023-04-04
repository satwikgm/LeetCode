//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
public:
    void fun(vector<vector<int>> &m , int n , int i , int j , vector<string> &ans , string s , bool vis[6][6])
    {
        if(i==n-1 && j==n-1)
        {
            if(m[i][j] == 1)
            {
                ans.push_back(s);
            }
            return;
        }
        
        if(m[i][j] == 0)
        {
            return;
        }
        else
        {
            vis[i][j]=1;  
            if(i-1 >= 0 && !vis[i-1][j])
            {
                fun(m,n,i-1,j,ans,s+"U",vis);
            }
            if(j-1 >= 0 && !vis[i][j-1])
            {
                fun(m,n,i,j-1,ans,s+"L",vis);
            }
            if(i+1 < n && !vis[i+1][j])
            {
                fun(m,n,i+1,j,ans,s+"D",vis);
            }
            if(j+1 < n && !vis[i][j+1])
            {
                fun(m,n,i,j+1,ans,s+"R",vis);
            }
            vis[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> ans;
        string s;
        bool vis[6][6];
        memset(vis,0,sizeof(vis));
        if(m[0][0] == 0)
        {
            return {};
        }
        fun(m,n,0,0,ans,s,vis);
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