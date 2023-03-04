//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(vector<int> &arr , int n , int i , vector<int> &memo)
    {
        if(i>=n-1)
        {
            return 0;
        }
        int c1=INT_MAX , c2=INT_MAX;
        if(memo[i]!=-1)
        {
            return memo[i];
        }
        if(i+1<n)
        {
            c1=abs(arr[i+1]-arr[i]);
        }
        if(i+2<n)
        {
            c2=abs(arr[i+2]-arr[i]);
        }
        return memo[i] = min( c1+fun(arr,n,i+1,memo) , c2+fun(arr,n,i+2,memo)  );
    }
    // int fun(vector<int> arr , int n)
    // {
    //     int dp[n];
    //     dp[0]=0;
    //     dp[1]=arr[1]-arr[0];
    //     dp[2]=min(abs(arr[2]-arr[0]) , abs(arr[2]-arr[1])+abs(arr[1]-arr[0]));
    //     for(int i=3;i<n;i++)
    //     {
    //         dp[i]=min()
    //     }
    // }
    int minimumEnergy(vector<int>& height, int n) 
    {
        vector<int> memo(n,-1);
        return fun(height,n,0,memo);
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