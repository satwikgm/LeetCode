class Solution {
public:
    static bool comp (vector<int> &a , vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int prev=intervals[0][1];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0] >= prev)
            {
                prev = intervals[i][1];
            }
            else 
            {
                ans++;
            }
        }
        return ans;
    }
};