class Solution {
public:
    void fun(int ind , vector<string> &ans , string curr , string s)
    {
        if(ind == s.size())
        {
            ans.push_back(curr);
            return;
        }
        if(s[ind] >= 'a' && s[ind] <= 'z')
        {
            curr += toupper(s[ind]);
            fun(ind+1 , ans , curr , s);
            curr.pop_back();
        }
        curr += s[ind];
        fun(ind+1 , ans , curr , s);
    }
    vector<string> letterCasePermutation(string s) 
    {
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
        vector<string> ans;
        string curr;
        fun(0 , ans , curr , s);
        return ans;
    }
};