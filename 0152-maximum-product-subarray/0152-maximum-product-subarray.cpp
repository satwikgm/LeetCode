class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int mn=nums[0],mx=nums[0],ans=nums[0];
        if(mx<mn)
        {
            swap(mx,mn);
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < 0)
            {
                swap(mx,mn);
            }
            mx *= nums[i];
            mn *= nums[i];
            if(nums[i] > mx)
            {
                mx=nums[i];
            }
            if(nums[i] < mn)
            {
                mn = nums[i];
            }
            ans = max(ans,mx);
        }
        return ans;
    }
};