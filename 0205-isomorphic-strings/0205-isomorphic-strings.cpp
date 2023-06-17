class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!=t.size())
        {
            return 0;
        }
        unordered_map<char,char> m,m1;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i]) != m.end())
            {
                if(t[i]!=m[s[i]])
                {
                    return 0;
                }
            }
            m[s[i]] = t[i];
        }
        for(int i=0;i<s.size();i++)
        {
            if(m1.find(t[i]) != m1.end())
            {
                if(s[i]!=m1[t[i]])
                {
                    return 0;
                }
            }
            m1[t[i]] = s[i];
        }
        return 1;
    }
};