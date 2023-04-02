class Solution {
public:
    #define vvi vector<vector<int>>
    #define vi vector<int>
    void fun(int ind , vi &arr , vvi &ans , vi &v , int k)
    {
        if(v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        if(ind == arr.size())
        {
            return;
        }
        // not pick
        fun(ind+1 , arr , ans , v , k);
        // pick
        v.push_back(arr[ind]);
        fun(ind+1 , arr , ans , v , k);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> arr(n,1);
        for(int i=1;i<n;i++)
        {
            arr[i] += arr[i-1];
        }
        vvi ans;
        vi v;
        fun(0,arr,ans,v,k);
        return ans;
    }
};