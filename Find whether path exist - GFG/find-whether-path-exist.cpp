//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        pair<int,int> src;
        pair<int,int> dst;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int dstX,dstY;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==2)
                {
                    dstX=i;
                    dstY=j;
                }
            }
        }
        bool visited[m][n];
        memset(visited,0,sizeof(visited));
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i==dstX && j==dstY)
            {
                return true;
            }
            visited[i][j]=1;
            if(i-1>=0 && grid[i-1][j]!=0 && !visited[i-1][j])
            {
                q.push({i-1,j});
                visited[i-1][j]=1;
                if(i-1==dstX && j==dstY)
                {
                    return true;
                }
            }
            if(i+1<m && grid[i+1][j]!=0 && !visited[i+1][j])
            {
                q.push({i+1,j});
                visited[i+1][j]=1;
                if(i+1==dstX && j==dstY)
                {
                    return true;
                }
            }
            if(j-1>=0 && grid[i][j-1]!=0 && !visited[i][j-1])
            {
                q.push({i,j-1});
                visited[i][j-1]=1;
                if(i==dstX && j-1==dstY)
                {
                    return true;
                }
            }
            if(j+1<n && grid[i][j+1]!=0 && !visited[i][j+1])
            {
                q.push({i,j+1});
                visited[i][j+1]=1;
                if(i==dstX && j+1==dstY)
                {
                    return true;
                }
            }
            
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends