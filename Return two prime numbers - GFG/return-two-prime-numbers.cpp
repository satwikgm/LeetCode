//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N)
    {
        vector<int> ans , v;
        
        bool vis[N+1];
        memset(vis,0,N+1);
        
        for(int i=2;i<=N;i++)
        {
            if(vis[i])
            {
                continue;
            }
            ans.push_back(i);
            for(int j=i*2;j<=N;j+=i)
            {
                vis[j]=1;
            }
        }
        
        int i=0 , j=ans.size()-1;
        while(i<=j)
        {
            if(ans[i]+ans[j]==N)
            {
                return {ans[i],ans[j]};
            }
            else if(ans[i]+ans[j]>N)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return {-1,-1};
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends