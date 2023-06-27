//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int fun1(vector<int> &h , int n)
    {
        int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            dp[i] = dp[i-1] + abs(h[i]-h[i-1]);
            if(i>1)
            {
                dp[i]=min(dp[i] , dp[i-2]+abs(h[i]-h[i-2]));
            }
        }
        return dp[n-1];
    }
    int minimumEnergy(vector<int>& height, int n) 
    {
        // memset(dp,-1,sizeof(dp));
        return fun1(height,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends