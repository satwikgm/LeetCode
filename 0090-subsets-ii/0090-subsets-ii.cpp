class Solution {
public:
    set<vector<int>> st;
    void fun(vector<int> &curr , vector<int> &arr , int i , int n)
    {
        if(i==n)
        {
            st.insert(curr);
            return;
        }
        // pick
        curr.push_back(arr[i]);
        fun(curr,arr,i+1,n);
        curr.pop_back();
        // not pick
        fun(curr,arr,i+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(),arr.end());
        fun(curr,arr,0,arr.size());
        for(auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};