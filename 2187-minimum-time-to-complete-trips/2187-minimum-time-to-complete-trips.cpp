class Solution {
public:
    bool fun(vector<int> &time , long long m , long long lim)
    {
        long long ans=0;
        for(long long it : time)
        {
            ans += m/it;
        }
        return ans>=lim;
    }
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long l=1,h=0,m,ans;
        long long mn=*min_element(time.begin(),time.end());
        h=mn*(long long)totalTrips;
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(fun(time,m,totalTrips))
            {
                ans=m;
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};