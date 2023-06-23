class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string s=strs[i];
            int j=0;
            for(j=0;j<s.size();j++)
            {
                if(ans[j] != s[j])
                {
                    ans=s.substr(0,j);
                    break;
                }
            }
            if(j==s.size())
            {
                ans=s;
            }
        }
        return ans;
    }
};