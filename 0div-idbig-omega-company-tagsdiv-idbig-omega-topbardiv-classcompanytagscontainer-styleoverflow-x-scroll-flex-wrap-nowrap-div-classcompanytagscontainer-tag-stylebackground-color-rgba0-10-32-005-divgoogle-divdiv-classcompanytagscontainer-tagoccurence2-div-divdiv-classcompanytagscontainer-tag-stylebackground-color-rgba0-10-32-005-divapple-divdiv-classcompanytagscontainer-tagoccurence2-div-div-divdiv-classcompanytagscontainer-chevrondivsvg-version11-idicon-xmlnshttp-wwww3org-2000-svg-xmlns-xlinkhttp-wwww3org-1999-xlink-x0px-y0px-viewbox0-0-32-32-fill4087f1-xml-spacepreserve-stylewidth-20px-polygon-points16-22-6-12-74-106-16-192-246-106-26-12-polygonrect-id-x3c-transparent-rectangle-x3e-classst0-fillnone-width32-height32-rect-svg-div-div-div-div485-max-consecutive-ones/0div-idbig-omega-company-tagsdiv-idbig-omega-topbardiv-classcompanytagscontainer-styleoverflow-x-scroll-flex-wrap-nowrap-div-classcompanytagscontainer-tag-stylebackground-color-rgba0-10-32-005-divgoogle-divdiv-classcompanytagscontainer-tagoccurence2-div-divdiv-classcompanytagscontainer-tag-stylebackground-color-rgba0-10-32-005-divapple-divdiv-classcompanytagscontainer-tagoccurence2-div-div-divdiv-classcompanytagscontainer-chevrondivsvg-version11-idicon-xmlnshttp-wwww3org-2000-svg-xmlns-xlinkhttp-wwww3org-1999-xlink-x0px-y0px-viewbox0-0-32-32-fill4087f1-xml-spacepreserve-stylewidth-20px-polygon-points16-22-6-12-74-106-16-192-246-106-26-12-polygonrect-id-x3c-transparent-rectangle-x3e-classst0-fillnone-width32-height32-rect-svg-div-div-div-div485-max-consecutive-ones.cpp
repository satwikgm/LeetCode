class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int i=-1,j=0;
        int n=a.size();
        int ans=0;
        while(j<n)
        {
            if(a[j]==0)
                i=j;
            if(a[j]==1)
                ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};