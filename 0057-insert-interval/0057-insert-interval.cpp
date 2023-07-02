class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) 
    {
        a.push_back(newInterval);
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        int end = a[0][1] , start = a[0][0];
        for(int i=1;i<a.size();i++)
        {
            if(a[i][0] <= end)
            {
                end=max(end , a[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start=a[i][0];
                end=a[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};