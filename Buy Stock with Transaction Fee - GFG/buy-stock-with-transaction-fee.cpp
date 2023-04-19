//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define ll long long
    // Changing Parameters -> i , buy
    ll funTab(vector<ll> &arr ,  int n , int fee)
    {
        ll dp[n+1][2];
        memset(dp,0,sizeof(dp));
        for(ll i=n-1;i>=0;i--)
        {
            for(ll buy=1;buy>=0;buy--)
            {
                if(buy)
                {
                    dp[i][buy] = max(-arr[i]-fee + dp[i+1][0]  ,  dp[i+1][1] );
                }
                else
                {
                    dp[i][buy] = max(arr[i] + dp[i+1][1]  ,  dp[i+1][0] );
                }
            }
        }
        return dp[0][1];
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) 
    {
        return funTab(prices , n , fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends