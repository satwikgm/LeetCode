class Solution {
public:
    int fun(vector<vector<int>>& e, int k , int ind , vector<vector<int>> &dp)
    {
        if(ind>=e.size() || k==0)
        {
            return 0;
        }
        if(dp[k][ind] != -1)
        {
            return dp[k][ind];
        }
        int i;
        for(i=ind+1;i<e.size();i++)
        {
            if(e[i][0] > e[ind][1])
            {
                break;
            }
        }
        // pick ind
        int x = e[ind][2] + fun(e,k-1,i,dp);
        // not pick ind 
        int y = fun(e,k,ind+1,dp);
        return dp[k][ind] = max  (  x,y );
    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
        int n=events.size();
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        sort(events.begin(),events.end());
        return fun(events,k,0,dp);
    }
};