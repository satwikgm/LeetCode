class Solution {
public:
    int fun(vector<int>& piles , int m , int h)
    {
        long long d=0;
        int wt=0;
        for(int i:piles)
        {
            int x=i/m;
            d+=x;
            if(i%m)
            {
                d+=1;
            }
        }
        return d<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l=1;
        int high=1000000000;
        int m,ans;
        while(l<=high)
        {
            m=(l)+(high-l)/2;
            if(fun(piles,m,h))
            {
                high=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return l;
    }
};