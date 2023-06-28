class Solution {
public:
    int fun(vector<int> &nums , int k)
    {
        int n=nums.size();
        unordered_map<int,int> m;
        int left=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i] % 2]++;
            while(m[1] > k)
            {
                m[nums[left]%2]--;
                ++left;
            }
            if(m[1] <= k)
            {
                ans += i-left+1;
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return fun(nums,k)-fun(nums,k-1);
    }
};