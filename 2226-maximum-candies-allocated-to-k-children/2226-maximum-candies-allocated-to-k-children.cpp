class Solution {
public:
    #define ll long long
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int l=0 , h=1e7;
        ll m;
        while(l < h)
        {
            m=(l+h+1)/2;
            ll cnt=0;
            for(int i=0;i<candies.size() && cnt<k;++i)
            {
                cnt += candies[i]/m;
            }
            if(cnt >= k)
            {
                l = m;
            }
            else
            {
                h = m-1;
            }
        }
        return l;
    }
};