class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int ans=0;
        int c0=0;
        int i=0,j=0;
        while(j<nums.size())
        {
            if(nums[j] == 0)
            {
                c0++;
            }
            if(c0 > 1)
            {
                while(c0 > 1)
                {
                    if(nums[i]==0)
                    {
                        c0--;
                    }
                    i++;
                }
            }
            if(c0 <= 1)
            {
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans-1;
    }
};