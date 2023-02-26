//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    // bool vis[101][101];
    void fun(vector<vector<char>>& grid , int a , int b , bool visited[101][101])
    {
        visited[a][b]=1;
        queue<pair<int,int>> q;
        q.push({a,b});
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> rowVar{-1,1,0,0};
        vector<int> colVar{0,0,1,-1};
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            visited[i][j]=1;
            for(int k=0;k<4;k++)
            {
                    int r = i+rowVar[k];
                    int c = j+colVar[k];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='X' && !visited[r][c])
                    {
                        q.push({r,c});
                        visited[r][c]=1;
                    }
            }
               
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        bool visited[101][101];
        memset(visited,0,sizeof(visited));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]=='X')
                {
                    fun(grid,i,j,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends