class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        // Staircase structure
        int m = grid.size();
        int n = grid[0].size();
        int r = m-1;
        int c = 0;
        int ans = 0;
        while(r>=0 && c<n)
        {
            if(grid[r][c] < 0)
            {
                r--;
                ans += n-c;
            }
            else
            {
                c++;
            }
        }
        return ans;
    }
};