class Solution {
public:
    int beautySum(string s) 
    {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int m[26];
            memset(m,0,sizeof(m));
            int mx=INT_MIN;
            int mn=INT_MAX;
            for(int j=i;j<s.size();j++)
            {
                m[s[j]-'a']++;
                mx = max(mx , m[s[j]-'a']);
                if(mn >= m[s[j]-'a']-1)
                {
                    mn = m[s[j]-'a'];
                    for(int it=0;it<26;it++)
                    {
                        if(m[it]==0)
                        {
                            continue;
                        }
                        mn = min(mn , m[it]);
                    }
                }
                ans += mx-mn;
            }
        }
        return ans;
    }
};