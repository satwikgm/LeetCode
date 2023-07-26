class Solution {
public:
    int dp[101];
    int fun(vector<int> &nums , int i)
    {
        if(i>=nums.size()) {
            return 0;
        }    
        if(dp[i] != -1)
        {
            return dp[i];
        }
        return dp[i] = max(nums[i]+fun(nums,i+2) , fun(nums,i+1));
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(nums,0);
    }
};