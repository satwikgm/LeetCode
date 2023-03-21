class Solution {
public:
    #define ll long long
    long long interchangeableRectangles(vector<vector<int>>& rectangles) 
    {
        vector<double> v;
        for(auto it : rectangles)
        {
            v.push_back((double)it[0] / (double)it[1]);
        }
        unordered_map<double,int> m;
        for(int i=0;i<v.size();i++)
        {
            m[v[i]]++;
        }
        ll ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(m[v[i]] >= 2)
            {
                ans += m[v[i]]-1;
            }
            m[v[i]]--;
        }
        return ans;
    }
};