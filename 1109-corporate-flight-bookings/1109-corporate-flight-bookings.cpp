class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int> ans(n,0);
        for(auto it : bookings)
        {
            int first=it[0],last=it[1],val=it[2];
            ans[first-1] += val;
            if(last < n)
            {
                ans[last] -= val;
            }
        }
        for(int i=1;i<n;i++)
        {
            ans[i] += ans[i-1];
        }
        return ans;
    }
};