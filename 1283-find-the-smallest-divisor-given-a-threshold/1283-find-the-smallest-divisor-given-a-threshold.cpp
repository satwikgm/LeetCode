class Solution {
public:
    int fun(vector<int>& nums , int m , int thr)
    {
        int d=0;
        for(int it : nums)
        {
            int rem = it/m;
            d+=rem;
            if(it%m)
            {
                d+=1;
            }
        }
        return d<=thr;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int l=1,h=1e6,m,ans;
        while(l<=h)
        {
            m=(l+h)/2;
            if(fun(nums,m,threshold))
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