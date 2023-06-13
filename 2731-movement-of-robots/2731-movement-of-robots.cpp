class Solution {
public:

    int mod = 1e9 + 7;
    #define ll long long int
    int sumDistance(vector<int>& nums, string s, int d) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(s[i]=='R')
            {
                nums[i]+=d;
            }
            else
            {
                nums[i]-=d;
            }
        }
        sort(nums.begin(),nums.end());
        ll ans=0;
        ll pref = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans += (i*(ll)nums[i] - pref)%mod;
            ans %= mod;
            pref += (ll)nums[i]%mod;
        }
        return (int)ans;
    }
};