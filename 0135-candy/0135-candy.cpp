class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            if(ratings[0]==ratings[1])
            {
                return 2;
            }
            return 3;
        }
        vector<int> v(n,1);
        for(int i=0;i<n;i++)
        {
            if(i-1>=0)
            {
                if(ratings[i]>ratings[i-1])
                {
                    v[i] = v[i-1] + 1;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)
            {
                if(ratings[i]>ratings[i+1])
                {
                    v[i] = max(v[i],v[i+1] + 1);
                }
            }
        }
        int ans = accumulate(v.begin(),v.end(),0);
        return ans;
    }
};