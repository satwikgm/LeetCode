//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    int fun(vector<int> &h , int n , int i)
    {
        if(i>=n-1)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int mx1=INT_MAX , mx2=INT_MAX;
        if(i+1<n)
        {
            mx1=min(mx1,abs(h[i+1] - h[i]));
        }
        if(i+2<n)
        {
            mx2=min(mx2,abs(h[i+2] - h[i]));
        }
        return dp[i] = min(mx1+fun(h,n,i+1),mx2+fun(h,n,i+2));
    }
public:
    int dp[100002];
    int minimumEnergy(vector<int>& height, int n) 
    {
        memset(dp,-1,sizeof(dp));
        return fun(height,n,0);
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