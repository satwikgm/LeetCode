class Solution {
public:
    void fun(int ind , vector<int> &temp , vector<vector<int>> &ans , vector<int> &v , int k , int n)
    {
        if(n==0 && k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(ind == v.size())
        {
            return;
        }
        if(n==0 || k==0)
        {
            return;
        }
        // not pick
        fun(ind+1 , temp , ans , v , k , n);
        // pick
        if(v[ind] <= n)
        {
            temp.push_back(v[ind]);
            fun(ind+1 , temp , ans , v , k-1 , n-v[ind]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0 , temp , ans , v , k , n);
        return ans;
    }
};