class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> lis;
        for(int i=0;i<nums.size();i++)
        {
            int ind = lower_bound(lis.begin() , lis.end() , nums[i]) - lis.begin();
            if(ind == lis.size())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                lis[ind]=nums[i];
            }
        }
        return lis.size();
    }
};