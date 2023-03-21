class Solution {
public:
    #define ll long long
    ll mod=1e9+7;
    int numSub(string s) 
    {
        ll n=s.size();
        ll i=0;
        ll j=0;
        ll ans=0;
        while(j<n)
        {
            if(s[j] != '1')
            {
                while(j<n && s[j] != '1')
                {
                    j++;
                }
            }
            i=j;
            while(j<n && s[j]=='1')
            {
                ans += j-i+1;
                j++;
            }
        }
        return ans%mod;
    }
};