class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return nums.size();
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        int ans=1,temp_ans=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == prev+1)
            {
                temp_ans++;
            }
            else if(nums[i] != prev)
            {
                temp_ans=1;
            }
            prev=nums[i];
            ans = max(ans , temp_ans);
        }
        return ans;
    }
};