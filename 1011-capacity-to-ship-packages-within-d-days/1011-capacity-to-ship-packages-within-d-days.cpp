class Solution {
public:
    bool fun(vector<int>& weights , int m , int days)
    {
        int d=1;
        int wt=0;
        for(int i=0;i<weights.size();i++)
        {
            if(wt+weights[i] > m)
            {
                d++;
                wt=0;
            }
            wt += weights[i];
        }
        if(d > days)
        {
            return 0;
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int l=0,h=0;
        int m;
        for(int i=0;i<weights.size();i++)
        {
            l=max(l,weights[i]);
            h+=weights[i];
        }
        int ans=h;
        while(l<=h)
        {
            m=(l+h)/2;
            if(fun(weights,m,days))
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