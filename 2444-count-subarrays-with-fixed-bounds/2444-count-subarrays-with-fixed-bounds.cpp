class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long long ans=0;
        int n=nums.size();
        int left=-1 , mx=-1 , mn=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=minK && nums[i]<=maxK)
            {
                if(nums[i]==minK)
                {
                    mn=i;
                }
                if(nums[i]==maxK)
                {
                    mx=i;
                }
                if(mn!=-1 && mx!=-1)
                {
                    ans += min(mn,mx)-left;
                }
            }
            else
            {
                left=i;
                mn=-1;
                mx=-1;
            }
        }
        return ans;
    }
};