class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        int i=0 , j=0;
        int ans=0,sum=0;
        unordered_map<int,int> m;
        while(j<n)
        {
            m[nums[j]]++;
            if(m[nums[j]] > 1)
            {
                while(i<j && m[nums[j]] > 1)
                {
                    m[nums[i]]--;
                    sum -= nums[i];
                    i++;
                }
            }
            sum+=nums[j];
            ans=max(ans , sum);
            j++;
        }
        return ans;
    }
};