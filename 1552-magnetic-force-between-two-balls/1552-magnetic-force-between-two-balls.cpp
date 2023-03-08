class Solution {
public:
    int fun(vector<int> &position , int mid , int m , int n)
    {
        int i=0,j=0;
        while(j<n && m)
        {
            while(j<n && position[j]-position[i] < mid)
            {
                j++;
            }
            if(j<n && position[j]-position[i]>=mid)
            {
                m--;
                i=j;
            }
        }
        return m<=0;
    }
    int maxDistance(vector<int>& position, int m) 
    {
        int n=position.size();
        sort(position.begin(),position.end());
        int l=1 , h=1e9;
        int ans,mid;
        while(l<=h)
        {
            mid=(l)+(h-l)/2;
            if(fun(position,mid,m-1,n))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};