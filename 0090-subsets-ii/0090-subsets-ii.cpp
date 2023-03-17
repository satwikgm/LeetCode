class Solution {
public:
    void fun(int ind , vector<int> &nums , set<vector<int>> &ans , vector<int> v)
    {
        if(ind==nums.size())
        {
            sort(v.begin(),v.end());
            ans.insert(v);
            return;
        }
        fun(ind+1,nums,ans,v);
        v.push_back(nums[ind]);
        fun(ind+1,nums,ans,v);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<vector<int>> ans;
        vector<int> v;
        fun(0,nums,ans,v);
        vector<vector<int>> answer;
        for(auto it : ans)
        {
            answer.push_back(it);
        }
        return answer;
    }
};