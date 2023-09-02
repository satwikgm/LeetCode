class Solution {
public:
    unordered_map<string,int> m;
    unordered_map<int,int> dp;
    int fun(string s , int ind)
    {
        if(ind>=s.size())
        {
            return 0;
        }
        if(dp.find(ind)!=dp.end())
        {
            return dp[ind];
        }
        int ans=INT_MAX;
        ans = 1+fun(s,ind+1);
        string temp="";
        for(int i=ind;i<s.size();i++)
        {
            temp+=s[i];
            if(m.find(temp) != m.end())
            {
                ans = min(ans , fun(s,i+1));
            }
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto it : dictionary)
        {
            m[it]++;
        }
        return fun(s,0);
    }
};