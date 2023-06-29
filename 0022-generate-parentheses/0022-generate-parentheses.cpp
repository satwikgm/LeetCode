class Solution {
public:
    void fun(int open , int close ,int n , string s, vector<string> &ans)
    {
        /*Base Case*/
        if(open==n && close==n)
        {
            ans.push_back(s);
            return;
        }
        if(open==close)
        {
            fun(open+1,close,n,s+'(',ans);
        }
        else if(open==n)
        {
            fun(open,close+1,n,s+')',ans);
        }
        else
        {
            fun(open+1,close,n,s+'(',ans);
            fun(open,close+1,n,s+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        int open=0,close=0;
        fun(open,close,n,"",ans);
        return ans;
    }
};