//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) 
    {
        int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int mx=1e9;
            int c=0;
            for(int j=i-k ; c<k ; j++)
            {
                if(j<0)
                {
                    c++;
                    continue;
                }
                mx=min(mx,dp[j] + abs(height[i]-height[j]));
                c++;
            }
            dp[i]=mx;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends