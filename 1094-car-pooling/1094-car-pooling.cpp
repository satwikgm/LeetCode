class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> ans(1002 , 0);
        for(auto it : trips)
        {
            if(it[0] > capacity)
            {
                return 0;
            }
            ans[it[1]] += it[0];
            ans[it[2]] -= it[0];
        }
        for(int i=1;i<ans.size();i++)
        {
            ans[i] += ans[i-1];
            if(ans[i] > capacity)
            {
                return 0;
            }
        }
        return 1;
    }
};