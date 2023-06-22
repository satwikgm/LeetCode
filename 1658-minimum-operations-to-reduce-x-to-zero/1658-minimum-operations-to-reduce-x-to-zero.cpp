class Solution {
public:
    #define ll long long
    int minOperations(vector<int>& nums, int x) 
    {
        ll sum = accumulate(nums.begin(),nums.end(),0);
        ll target = sum - x;
        if(target<0)
        {
            return -1;
        }
        sum=0;
        int i=0;
        int ans=0;
        bool fl=0;
        for(int j=0;j<nums.size();j++)
        {
            sum += nums[j];
            while(sum>target && i<nums.size())
            {
                sum -= nums[i++];
            }
            if(sum==target)
            {
                fl=1;
                ans=max({ans,j-i+1});
            }
        }
        if(!fl)
        {
            return -1;
        }
        return nums.size()-ans;
    }
};