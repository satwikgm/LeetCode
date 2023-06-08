class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int ans=0,sum=0;
        int i;
        for(i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        i=k-1;
        int j = cardPoints.size()-1;
        ans=sum;
        while(i>=0)
        {
            sum -= cardPoints[i];
            i--;
            sum += cardPoints[j];
            j--;
            ans = max(ans , sum);
        }
        return ans;
    }
};