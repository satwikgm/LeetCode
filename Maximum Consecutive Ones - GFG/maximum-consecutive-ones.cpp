//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) 
    {
        int i=0 , j=0 , ct=0 , ans=0;
        while(j<n)
        {
            if(nums[j]==0)
            {
                ct++;
            }
            if(ct<=k)
            {
                ans=max(ans,j-i+1);
            }
            else
            {
                while(ct>k)
                {
                    if(nums[i]==0)
                    {
                        ct--;
                    }
                    i++;
                }
            }
            j++;
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
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends