//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        int sum = 0 , ans = 0;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            sum += nums[i]%2;
            m[sum]++;
            if(m.find(sum-k) != m.end())
            {
                ans += m[sum-k];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends