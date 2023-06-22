class Solution {
public:
    int memo[50001][2];
    // memset()
    int fun(int i , vector<int> &prices , int fee , bool canBuy , int n)
    {
        if(n==i)
        {
            return 0;
        }
        if(memo[i][canBuy])
        {
            return memo[i][canBuy];
        }
        if(canBuy)
        {
            return memo[i][canBuy] = max(-prices[i] + fun(i+1,prices,fee,0,n) , fun(i+1,prices,fee,1,n));
        }
        else
        {
            return memo[i][canBuy] = max(prices[i]-fee+fun(i+1,prices,fee,1,n) , fun(i+1,prices,fee,0,n));
        }
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        return fun(0,prices,fee,1,prices.size());
    }
};