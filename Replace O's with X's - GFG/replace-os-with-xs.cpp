//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        m=mat.size();
        n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || j==0 || i==m-1 || j==n-1) && (mat[i][j]=='O'))
                {
                    q.push({i,j});
                }
            }
        }
        bool vis[m][n];
        memset(vis,0,sizeof(vis));
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            vis[i][j]=1;
            if(i-1>=0 && mat[i-1][j]=='O' && !vis[i-1][j])
            {
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(j-1>=0 && mat[i][j-1]=='O' && !vis[i][j-1])
            {
                q.push({i,j-1});
                vis[i][j-1]=1;
            }
            if(i+1<m && mat[i+1][j]=='O' && !vis[i+1][j])
            {
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if(j+1<n && mat[i][j+1]=='O' && !vis[i][j+1])
            {
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && mat[i][j]=='O')
                {
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends