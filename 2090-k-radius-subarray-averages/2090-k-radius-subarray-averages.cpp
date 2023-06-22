class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i] = -1*nums[i];
        }
        int i=0;
        long long sum=0;
        for(int j=0;j<n;j++)
        {
            sum += nums[j];
            if(j>k)
            {
                sum -= nums[i++];
            }
            ans[i]+=sum;
        }
        sum=0;
        i=n-1;
        for(int j=n-1;j>=0;j--)
        {
            sum += nums[j];
            if(j<n-k-1)
            {
                sum -= nums[i--];
            }
            ans[i] += sum;
        }
        for(int i=0;i<n;i++)
        {
            ans[i] = ans[i]/(2*k+1);
            if(i<k || i>=n-k)
            {
                ans[i]=-1;
            }
        }
        vector<int> anss(n,0);
        for(int i=0;i<n;i++)
        {
            anss[i]=(int)ans[i];
        }
        return anss;
    }
};