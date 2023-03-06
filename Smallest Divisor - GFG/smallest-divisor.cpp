//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fun(vector<int>& nums , int m , int K)
    {
        int d=0;
        for(int it : nums)
        {
            int rem = it/m;
            d+=rem;
            if(it%m)
            {
                d+=1;
            }
        }
        return d<=K;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        int l=1 , h=1e9,m,ans;
        while(l<=h)
        {
            m=(l+h)/2;
            if(fun(nums,m,K))
            {
                ans=m;h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends