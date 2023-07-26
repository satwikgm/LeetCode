class Solution {
public:
    set<string> dict;
    unordered_map<int,int> dp;
    bool fun(string s , int i , vector<int> &dp) {
        if(i==s.size()) {
            return 1;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        for(int k=i;k<s.size();k++) {
            string temp = s.substr(i,k-i+1);
            if( (  dict.find(temp) != dict.end()) && fun(s,k+1,dp)) {
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string sm="leetcode";
        cout<<sm.substr(1,4);
        vector<int> dp(s.size()+1,-1);
        for(auto it : wordDict) {
            dict.insert(it);
        }
        return fun(s,0,dp);
    }
};