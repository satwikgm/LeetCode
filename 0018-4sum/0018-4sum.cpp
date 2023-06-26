class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;   
            }
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                {
                    continue;
                }
                long long x = (long long)target - (long long)nums[i] - (long long)nums[j];
                int s = j+1 , e=n-1;
                while(s<e)
                {
                    if(nums[s]+nums[e]==x)
                    {
                        st.insert({nums[i],nums[j],nums[s],nums[e]});
                        while(s+1<n && nums[s]==nums[s+1])
                        {
                            s++;
                        }
                        while(e-1>=0 && nums[e]==nums[e-1])
                        {
                            e--;
                        }
                        s++;
                        e--;
                    }
                    else if(nums[s]+nums[e]>x)
                    {
                        e--;
                    }
                    else
                    {
                        s++;
                    }
                }
            }
        }
        for(auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};