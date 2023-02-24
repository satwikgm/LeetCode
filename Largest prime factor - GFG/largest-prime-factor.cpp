//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N)
    {
        int n=N;
        bool vis[n+1];
        memset(vis,0,sizeof(vis));
        
        vector<int> prime;
        
        for(int i=2;i<=n;i++)
        {
            if(vis[i])
            {
                continue;
            }
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i)
            {
                vis[j]=1;
            }
        }
        int ans=2;
        for(int i=0;i<prime.size();i++)
        {
            if(n%prime[i]==0)
            {
                ans=max(ans,prime[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends