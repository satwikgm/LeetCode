class Solution {
public:
    int memo[21][21];
    int fun(vector<int> &a , int i , int j)
    {
        if(i>j)
        {
            return 0;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        if(i==j)
        {
            return  a[i];
        }
        return memo[i][j] = max(a[i]+min(fun(a,i+2,j),fun(a,i+1,j-1)),a[j]+min(fun(a,i+1,j-1),fun(a,i,j-2)));
    }
    bool PredictTheWinner(vector<int>& nums) 
    {
        memset(memo,-1,sizeof(memo));
        int totScore = 0;
        int aScore = fun(nums,0,nums.size()-1);
        for(auto a : nums)
        {
            totScore+=a;
        }
        if(aScore>=totScore-aScore)
        {
            return true;
        }
        return false;
    }
};