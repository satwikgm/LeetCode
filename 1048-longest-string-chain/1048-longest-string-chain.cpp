class Solution {
public:
    bool fun(string &a , string &b)
    {
        if(a.size()+1 != b.size())
        {
            return 0;
        }
        int i=0 , j=0;
        while(j<b.size())
        {
            if(i<a.size() && a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return (i==a.size() && j==b.size());
    }
    static bool cmp(string s1 , string s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),cmp);
        int ans=1;
        int n = words.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(fun(words[j] , words[i]))
                {
                    dp[i] = max(dp[i] , 1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};