class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        vector<int> temp;
        temp.push_back(0);
        for(int i=0;i<gain.size();i++)
        {
            temp.push_back(temp[i]+gain[i]);
        }
        int ans = *max_element(temp.begin(),temp.end());      
        return ans;
    }
};