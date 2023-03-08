class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n=bloomDay.size();
        if((long long)m*(long long)k>(long long)n)
        {
            return -1;
        }
        int low=1 , high=1e9;
        int ans,mid;
        while(low<=high)
        {
            mid=(low)+(high-low)/2;
            int cnt=0,num=0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i] <= mid)
                {
                    cnt++;
                }
                else
                {
                    cnt=0;
                    continue;
                }
                if(cnt%k==0)
                {
                    num++;
                    cnt=0;
                }
            }
            if(num>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};