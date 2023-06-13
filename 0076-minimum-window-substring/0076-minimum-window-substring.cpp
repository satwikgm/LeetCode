class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(t.size() == 1)
        {
            if(s.find(t) != s.npos)
            {
                return t;
            }
            return "";
        }
        if(s.find(t) != s.npos)
        {
            return t;
        }
        unordered_map<char,int> m1;
        for(int i=0;i<t.size();i++)
        {
            m1[t[i]]++;
        }
        string ans;
        int res=INT_MAX;
        int ctr=0;
        int desiredCtr=t.size();
        unordered_map<char,int> m;
        int j=0 , i=0;
        while(j<s.size())
        {
            if(m1.find(s[j]) != m1.end())
            {
                m[s[j]]++;
                if(m[s[j]] <= m1[s[j]])
                {
                    ctr++;
                }
            }
            if(ctr == desiredCtr)
            {
                if(res >= j-i+1)
                {
                    res = j-i+1;
                    ans = s.substr(i , j-i+1);
                }
                while(i<j && ctr == desiredCtr)
                {
                    if(res >= j-i+1)
                    {
                        res = j-i+1;
                        ans = s.substr(i , j-i+1);
                    }
                    if(m1.find(s[i]) != m1.end())
                    {
                        m[s[i]]--;
                        if(m[s[i]] < m1[s[i]])
                        {
                            ctr--;
                        }
                        if(m[s[i]] == 0)
                        {
                            m.erase(s[i]);
                        }
                    }
                    if(ctr == desiredCtr)
                    {
                        i++;
                        if(res >= j-i+1)
                        {
                            ans = s.substr(i , j-i+1);
                        }
                    }
                    else
                    {
                        i++;
                        break;
                    }
                }
            }
            
            j++;
        }
        return ans;
    }
};