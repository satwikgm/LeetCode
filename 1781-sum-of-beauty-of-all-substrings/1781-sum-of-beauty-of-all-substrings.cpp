class Solution {
public:
    int beautySum(string s) 
    {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            unordered_map<char,int> m;
            int mx=INT_MIN;
            int mn=INT_MAX;
            for(int j=i;j<s.size();j++)
            {
                m[s[j]]++;
                mx = max(mx , m[s[j]]);
                if(mn >= m[s[j]]-1)
                {
                    mn = m[s[j]];
                    for(auto it : m)
                    {
                        mn = min(mn , it.second);
                    }
                }
                ans += mx-mn;
            }
        }
        return ans;
    }
};