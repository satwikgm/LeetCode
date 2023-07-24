class Solution {
public:
    void fun(int ind , set<vector<int>> &ans , vector<int> &nums) {
        if(ind == nums.size()) {
            ans.insert(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++) {
            swap(nums[ind],nums[i]);
            fun(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> anss;
        vector<int> v;
        fun(0,anss,nums);
        for(auto it : anss)
        {
            ans.push_back(it);
        }
        return ans;
    }
};