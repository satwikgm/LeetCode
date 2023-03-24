//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int fun(vector<int> &arr , int i , int j , vector<vector<int>> &dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans=INT_MIN , temp;
        for(int k=i;k<j;k++)
        {
            temp = arr[i-1]*arr[k]*arr[j] + fun(arr , i , k , dp) + fun(arr , k+1 , j , dp);
            
            ans = max(ans , temp);
            dp[i][j]=ans;
        }
        return dp[i][j] = ans;
    }
    int maxCoins(int N, vector<int> &arr) 
    {
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        N=arr.size();
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return fun(arr,1,N-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends