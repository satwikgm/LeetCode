class Solution {
public:
    int ans = 1e8;
    void fun(int ind , vector<int> v , int k , vector<int> &arr)
    {
        if(ind == arr.size())
        {
            int mx = INT_MIN;
            for(int i=0;i<k;i++)
            {
                mx = max(mx , v[i]);
            }
            ans=min(ans , mx);
            return;
        }
        for(int i=0;i<k;i++)
        {
            v[i] += arr[ind];
            fun(ind+1,v,k,arr);
            v[i] -= arr[ind];
            if(!v[i])
            {
                break;
            }
        }
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int> v(k,0);
        fun(0,v,k,cookies);
        return ans;
    }
};