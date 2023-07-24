class Solution {
public:
    vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void fun(int ind , string digits , string temp , vector<string> &ans) {
        if(ind == digits.size()) {
            ans.push_back(temp);
            return;
        }
        int vIndex = digits[ind] - '0';
        string s = v[vIndex];
        for(int i=0;i<s.size();i++) {
            temp += s[i];
            fun(ind+1,digits,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits=="")
        {
            return {};
        }
        string temp;
        vector<string> ans;
        fun(0,digits,temp,ans);
        return ans;
    }
};