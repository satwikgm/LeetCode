class Solution {
public:
    int fun(vector<int> &nums , int k)
    {
        int n=nums.size();
        int i=0 , j=0;
        unordered_map<int,int> m;
        int ans = 0;
        while(j<n)
        {
            m[nums[j]]++;
            while(m.size() > k)
            {
                m[nums[i]]--;
                if(m[nums[i]] == 0)
                {
                    m.erase(nums[i]);
                }
                i++;
            }
            if(m.size()<=k)
            {
                ans+=j-i+1;
            }
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return fun(nums,k)-fun(nums,k-1);
    }
};