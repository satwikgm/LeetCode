//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        for(int i=0;i<N;i++)
        {
            dp[0][i] = Matrix[0][i]; 
        }
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                dp[i][j]=Matrix[i][j];
                int mx=0;
                if(j-1>=0)
                {
                    mx=max(mx,dp[i-1][j-1]);
                }
                mx=max(mx,dp[i-1][j]);
                if(j+1<N)
                {
                    mx=max(mx,dp[i-1][j+1]);
                }
                dp[i][j]+=mx;
            }
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            ans=max(ans,dp[N-1][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends