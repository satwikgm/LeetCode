class Solution {
public:
    long long int memo[3220][1001];
    const int mod = 1e9 + 7;
    long long int fun(int s , int e , int k)
    {
        if(s==e)
        {
            if(k==0)
            {
                return 1;
            }
        }
        if(k==0)
        {
            return 0;
        }
        if(memo[s+1000][k]!=-1)
        {
            return memo[s+1000][k]%mod;
        }
        long long int ans1 = fun(s+1,e,k-1);
        long long int ans2 = 0;
        if(k-1 >= e-s+1)
        {
            ans2 = fun(s-1,e,k-1)%mod;
        }
        return memo[s+1000][k] = (ans1+ans2)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) 
    {
        if(abs(startPos-endPos)>k) return 0;
        memset(memo,-1,sizeof(memo));
        return fun(startPos,endPos,k)%mod;
    }
};
