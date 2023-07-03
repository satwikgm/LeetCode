class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]==target)
            {
                return m;
            }
            if(nums[m] < nums[h])       // right sorted
            {
                if(nums[m] <= target && nums[h] >= target)
                {
                    l = m+1;
                }
                else
                {
                    h = m-1;
                }
            }
            else        // left sorted
            {
                if(nums[m] >= target && nums[l] <= target)
                {
                    h = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
        }
        return -1;
    }
};