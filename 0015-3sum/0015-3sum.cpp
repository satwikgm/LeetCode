class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int x = nums[i];
            x *= -1;
            int s=i+1 , e = n-1;
            while(s<e)
            {
                if(nums[s]+nums[e] == x)
                {
                    ans.push_back({nums[i] , nums[s] , nums[e] });
                    while(s+1<n && nums[s]==nums[s+1])
                    {
                        s++;
                    }
                    while(e-1>=0 && nums[e-1]==nums[e])
                    {
                        e--;
                    }
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e] < x)
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return ans;
    }
};