class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        int n=flowers.size();
        vector<int> start,end,ans;
        for(int i=0;i<n;i++)
        {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(int i=0;i<persons.size();i++)
        {
            int x = persons[i];
            
            int ubIndex = upper_bound(start.begin(),start.end(),x)-start.begin();
            
            int ubIndex2 = lower_bound(end.begin(),end.end(),x)-end.begin();
            
            ans.push_back(ubIndex-ubIndex2);
        }
        return ans;
    }
};