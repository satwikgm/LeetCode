class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> lis(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    lis[i]=max(lis[i] , 1+lis[j]);
                }
            }
        } 
        for(int i=1;i<n;i++)
        {
            int l=0 , h=i-1 , m;
            while(l<=h)
            {
                m=(l+h)/2;
                if(nums[m] < nums[i])
                {
                    lis[i]=max(lis[i] , 1+lis[m]);
                    l=m+1;
                }
                else
                {
                    h=m-1;
                }
            }
        }
        return *max_element(lis.begin(),lis.end());

    }
};