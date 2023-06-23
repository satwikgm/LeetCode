class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        int n=arr.size();
        int ans=1;
        unordered_map<int,int> m;
        for(int i=n-1;i>=0;i--)
        {
            m[arr[i]] = 1+m[arr[i]+difference];
            ans=max(ans,m[arr[i]]);
        }
        return ans;
    }
};