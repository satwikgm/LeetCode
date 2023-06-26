class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0,curr=0;
        int temp_ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i] - 1) == s.end())
            {
                curr = nums[i];
                temp_ans=1;
            }
            while(s.find(curr+1) != s.end())
            {
                curr = curr + 1;
                temp_ans++;
            }
            ans=max(ans,temp_ans);
        }
        return ans;
    }
};