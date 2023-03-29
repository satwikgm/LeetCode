class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int res=0;
        int curr_sum=0;
        int curr=0;
        for(int i=n-1;i>=0;i--)
        {
            curr_sum=curr_sum+satisfaction[i];
            curr=curr+curr_sum;
            res=max(res,curr);
        }
        return res;
    }
};