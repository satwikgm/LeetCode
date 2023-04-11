class Solution {
public:
    string removeStars(string s) 
    {
        string ans="";
        stack<char> st;
        for(int i : s)
        {
            if(i == '*')
            {
                if(st.size())
                    st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        while(st.size())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};