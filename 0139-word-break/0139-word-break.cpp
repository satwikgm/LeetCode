class Solution {
public:
    set<string> dict;
    unordered_map<int,int> dp;
    bool fun(string s , int i) {
        if(i==s.size()) {
            return 1;
        }
        if(dp.find(i) != dp.end()) {
            return dp[i];
        }
        for(int k=i;k<s.size();k++) {
            string temp = s.substr(i,k-i+1);
            if( (  dict.find(temp) != dict.end()) && fun(s,k+1)) {
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string sm="leetcode";
        cout<<sm.substr(1,4);
        for(auto it : wordDict) {
            dict.insert(it);
        }
        return fun(s,0);
    }
};