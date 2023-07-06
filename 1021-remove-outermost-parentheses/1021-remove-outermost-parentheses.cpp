class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        set<int> st;
        int open=0,close=0,start=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            if(s[i]==')')
            {
                close++;
            }
            if(open==close)
            {
                st.insert(start);
                st.insert(i);
                start = i+1;
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(st.find(i)!=st.end())
            {
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};