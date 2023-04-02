class Solution {
public:
    vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void fun(string digits , int ind , vector<string> &ans , string s)
    {
        if(ind >= digits.size())
        {
            ans.push_back(s);
            return;
        }
        string str = v[digits[ind] - '0'];
        for(int i=0;i<str.size();i++)
        {
            s += str[i];
            fun(digits , ind+1 , ans , s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits == "")
        {
            return {};
        }
        vector<string> ans;
        string s="";
        fun(digits , 0 , ans , s);
        return ans;
    }
};