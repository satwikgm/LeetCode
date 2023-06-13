class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();
        map<vector<int>, int> m;
        for(int i=0;i<n;i++)
        {
            m[grid[i]]++; 
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                v.push_back(grid[j][i]);
            }
            ans += m[v];
        }
        return ans;
    }
};