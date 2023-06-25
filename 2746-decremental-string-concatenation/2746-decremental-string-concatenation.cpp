class Solution {
public:
    int fun(int i , char start , char end , vector<string> &words , int dp[51][26][26])
    {
        if(i==words.size())
        {
            return 0;
        }
        
        if(dp[i][start-'a'][end-'a'] != -1)
        {
            return dp[i][start-'a'][end-'a'];
        }
        
        int a=1e9,b=1e9;
        
        if(end == words[i][0])
        {
            a = words[i].size()-1 + fun(i+1,start,words[i].back(),words,dp);
        }
        else
        {
            a = words[i].size() + fun(i+1,start,words[i].back(),words,dp);
        }
        
        if(start == words[i].back())
        {
            b = words[i].size()-1 + fun(i+1,words[i][0],end,words,dp);
        }
        else
        {
            b = words[i].size() + fun(i+1,words[i][0],end,words,dp);
        }
        
        return dp[i][start-'a'][end-'a'] = min(a,b);
    }
    int minimizeConcatenatedLength(vector<string>& words) 
    {
        int dp[1001][26][26];
        memset(dp,-1,sizeof(dp));
        return words[0].size() + fun(1,words[0][0] , words[0].back() , words , dp);
    }
};