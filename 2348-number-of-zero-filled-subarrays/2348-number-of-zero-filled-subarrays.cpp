class Solution {
public:
    #define ll long long
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        ll n=nums.size();
        ll ans=0;
        ll i=0,j=0;
        while(j<n)
        {
            if(j<n && nums[j]!=0)
            {
                while(j<n && nums[j]!=0)
                {
                    j++;
                }
            }
            i=j;
            while(j<n && nums[j]==0)
            {
                ans += j-i+1;
                j++;
            }
        }
        return ans;
    }
};