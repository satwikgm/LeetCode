//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& bt) 
    {
        int n=bt.size();
        sort(bt.begin(),bt.end());
        vector<int> v;
        v.push_back(bt[0]);
        for(int i=1;i<n;i++)
        {
            v.push_back(v.back()+bt[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans += v[i];
        }
        return ans/n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        int ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends