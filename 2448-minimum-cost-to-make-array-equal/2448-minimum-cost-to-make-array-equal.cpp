class Solution {
public:
    #define ll long long
    ll fun(vector<int> &nums , vector<int> &cost , ll m)
    {
        ll sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + abs(m-nums[i])*cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        ll n=nums.size();
        
        ll l = 1;
        ll h = 1000000;
        
        ll m,ans=fun(nums,cost,h);
        
        while(l<=h)
        {
            m = (l+h)/2;
            
            ll x = fun(nums,cost,m);
            ll y = fun(nums,cost,m+1);
            
            if(x>=y)
            {
                l = m+1;
            }
            else
            {
                h = m-1;
            }
            ans = min({ans,x,y});
        }
        return ans;
    }
};