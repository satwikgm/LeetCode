class Solution {
public:
    bool fun(vector<int>& nums, int p , int m)
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1] - nums[i] <= m)
            {
                count++;
                i++;
            }
            if(count == p)
            {
                return 1;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0 , h=1e9 , ans , m;
        while(l<=h)
        {
            m=(l+h)/2;
            if(fun(nums,p,m))
            {
                ans=m;
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};