class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
        vector<int> ans(2051,0);
        for(auto it : logs)
        {
            int birth = it[0];
            int death = it[1];
            ans[birth] += 1;
            ans[death] -= 1;
        }
        int mx=0;
        int res=0;
        for(int i=1;i<ans.size();i++)
        {
            ans[i] += ans[i-1];
            if(ans[i] > mx)
            {
                res=i;
                mx = ans[i];
            }
        }
        return res;
    }
};