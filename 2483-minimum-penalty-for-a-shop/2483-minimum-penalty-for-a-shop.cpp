class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n=customers.size();
        vector<int> no(n+1,0) , yes(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(customers[i-1] == 'N')
            {
                no[i] = no[i-1] + 1;
            }
            else
            {
                no[i] = no[i-1];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(customers[i] == 'Y')
            {
                yes[i] = 1 + yes[i+1];
            }
            else
            {
                yes[i] = yes[i+1];
            }
        }
        vector<int> v(n+1,0);
        for(int i=0;i<=n;i++)
        {
            v[i] = yes[i]+no[i];
        }
        int idx=0 , mx = v[0];
        for(int i=0;i<=n;i++)
        {
            if(v[i] < mx)
            {
                mx = v[i];
                idx = i;
            }
        }
        return idx;
    }
};