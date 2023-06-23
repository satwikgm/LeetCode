class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        int n = nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            int c=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%p==0)
                {
                    c++;
                }
                if(c<=k)
                {
                    v.push_back(nums[j]);
                    ans.insert(v);
                }
            }
        }
        return ans.size();
    }
};