class Solution {
public:
    #define ll long long
    int bSearch(vector<int> &nums , int val, int n)
    {
        ll l=0,h=n;
        ll m;
        ll ind=n-1;
        while(l<=h)
        {
            m=(l+h)/2;
            if(m>=n)
            {
                h-=1;
                continue;
            }
            if(nums[m] > val)
            {
                h=m-1;
            }
            else
            {
                ind=m;
                l=m+1;
            }
        }
        return ind;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) 
    {
        vector<ll> ans;
        ll n = nums.size();
        vector<ll> pref(n+1,0);
        sort(nums.begin(),nums.end());
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1]+nums[i-1];
        }
        for(int i=0;i<queries.size();i++)
        {
            ll qVal = (ll)queries[i];
            ll ind = upper_bound(nums.begin(),nums.end(),qVal) - nums.begin();
            ll pus = (qVal*(ind) - pref[ind]) + ( (pref.back() - pref[ind]) - (qVal*(n-ind)   )  );
            ans.push_back(pus);
        }
        return ans;
    }
};