class Solution {
public:
    #define ll long long
    bool fun(vector<ll> nums , int m)
    {
        if(nums[0] > m)
        {
            return 0;
        }
        ll mx = m;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i] > m)
            {
                nums[i-1] += (nums[i] - m);
                nums[i] = m;
            }
            mx = max(mx , nums[i]);
        }
        mx = max(mx , nums[0]);
        return mx <= m;
    }
    int minimizeArrayValue(vector<int>& nums) 
    {
        vector<ll> arr;
        for(int i : nums)
        {
            arr.push_back(i);
        }
        long long l=*min_element(nums.begin(),nums.end());
        ll h=*max_element(nums.begin(),nums.end());
        long long m;
        long long ans=*max_element(nums.begin(),nums.end());
        while(l <= h)
        {
            m = (l+h)/2;
            if(fun(arr,m))
            {
                ans = m;
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};