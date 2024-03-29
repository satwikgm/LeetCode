class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) dp[i]=1;
        int ans=1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i] , 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};