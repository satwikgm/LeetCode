class Solution {
public:
    int fun(vector<int> &nums , int k)
    {
        if(k==0)
        {
            return 1;
        }
        if(dp[k] != -1)
        {
            return dp[k];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <= k)
            {
                ans += fun(nums,k-nums[i]);
            }
        }
        return dp[k] = ans;
    }
    int dp[1001];
    int combinationSum4(vector<int>& nums, int target) 
    {
        memset(dp,-1,sizeof(dp));
        return fun(nums,target);
    }
};