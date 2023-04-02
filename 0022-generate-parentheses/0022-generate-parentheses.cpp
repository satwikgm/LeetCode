class Solution {
public:
    // m => '('    n => ')'
    void fun(vector<string> &ans , string s , int m , int n)
    {
        if(m==0 && n==0)
        {
            ans.push_back(s);
            return;
        }
        if(m==n)
        {
            fun(ans , s + '(' , m-1 , n);
        }
        else if(m==0)
        {
            fun(ans , s+')' , m , n-1);
        }
        else
        {
            // pick (
            fun(ans , s+'(' , m-1 , n);
            // pick )
            fun(ans , s+')' , m , n-1);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string s;
        fun(ans,s,n,n);
        return ans;
    }
};