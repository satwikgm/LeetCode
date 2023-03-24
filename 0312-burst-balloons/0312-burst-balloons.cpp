class Solution {
public:
    int fun(vector<int> &arr , int i , int j , vector<vector<int>> &dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans=INT_MIN , temp;
        for(int k=i;k<j;k++)
        {
            temp = arr[i-1]*arr[k]*arr[j] + fun(arr , i , k , dp) + fun(arr , k+1 , j , dp);
            
            ans = max(ans , temp);
            dp[i][j]=ans;
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size() , vector<int> (nums.size() , -1));
        return fun(nums,1,nums.size()-1,dp);
    }
};