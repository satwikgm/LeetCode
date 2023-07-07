class Solution {
public:
    int fun(vector<int> &nums , int k)
    {
        if(k==0)
        {
            return 1;
        }
        if(m.find(k) != m.end())
        {
            return m[k];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <= k)
            {
                ans += fun(nums,k-nums[i]);
            }
        }
        return m[k] = ans;
    }
    unordered_map<int,int> m;
    int combinationSum4(vector<int>& nums, int target) 
    {
        return fun(nums,target);
    }
};