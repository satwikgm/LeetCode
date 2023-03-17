class Solution {
public:
    void fun(int ind , vector<int> &nums , vector<vector<int>> &ans , vector<int> v)
    {
        if(ind==nums.size())
        {
            ans.push_back(v);
            return;
        }
        fun(ind+1,nums,ans,v);
        v.push_back(nums[ind]);
        fun(ind+1,nums,ans,v);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        fun(0,nums,ans,v);
        return ans;
    }
};