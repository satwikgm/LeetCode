class Solution {
public:
    bool fun(vector<int>& nums , int m , int k)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int rem = nums[i]/m;
            cnt+=rem;
            if(nums[i]%m==0)
            {
                cnt--;
            }
        }
        return cnt<=k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int l=1 , h=*max_element(nums.begin(),nums.end()) , m , ans;
        while(l<=h)
        {
            m=(l+h)/2;              // Penalty
            if(fun(nums,m,maxOperations))
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