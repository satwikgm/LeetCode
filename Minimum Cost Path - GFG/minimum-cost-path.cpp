//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	#define ppi pair<int,pair<int,int>>
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=1e9;
            }
        }
        ans[0][0]=grid[0][0];
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({ans[0][0] , {0,0}});
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!pq.empty())
        {
            ppi p = pq.top();
            pq.pop();
            int dist = p.first;
            int i = p.second.first;
            int j = p.second.second;
            if(i==m-1 && j==n-1)
            {
                return dist;
            }
            for(int k=0;k<4;k++)
            {
                int nr = i+dx[k];
                int nc = j+dy[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n)
                {
                    int newDist = dist+grid[nr][nc];
                    if(newDist < ans[nr][nc])
                    {
                        ans[nr][nc] = newDist;
                        pq.push({newDist , {nr,nc}});
                    }
                }
            }
        }
        return -1;
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends