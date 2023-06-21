class Solution {
public:
    #define ll long long
    ll fun(vector<int> &nums , int m)
    {
        ll sum=0;  
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + abs(nums[i]-m);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) 
    {
        ll l=*min_element(nums.begin(),nums.end());
        ll h=*max_element(nums.begin(),nums.end());
        ll m,ans=999999999999999999;
        while(l<=h)
        {
            m=(l+h)/2;
            ll x = fun(nums,m);
            ll y = fun(nums,m+1);
            if(x>=y)
            {
                l=m+1;
            }
            else
            {
                h=m-1;
            }
            ans=min({ans,x,y});
        }
        return ans;
    }
};