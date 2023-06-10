class Solution {
public:
    #define ll long long
    long long matrixSumQueries(int n, vector<vector<int>>& queries) 
    {
        ll ans=0;
        ll row = n , col = n;
        unordered_set<int> rS , cS;
        for(int i = queries.size()-1;i>=0;i--)
        {
            
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];
            
            if(type==0)
            {
                if(rS.find(index) != rS.end())
                {
                    continue;
                }
                row--;
                ans += val*col;
                rS.insert(index);
            }
            else
            {
                if(cS.find(index) != cS.end())
                {
                    continue;
                }
                col--;
                ans += val*row;
                cS.insert(index);
            }
        }
        return ans;
    }
};