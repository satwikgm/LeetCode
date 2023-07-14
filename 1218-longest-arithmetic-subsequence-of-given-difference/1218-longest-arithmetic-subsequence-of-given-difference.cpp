class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        if(arr.size()==0)
        {
            return 0;
        }
        int ans=1;
        unordered_map<int,int> m;       // elem length of ap ending at it
        for(int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i]-difference) != m.end())
            {
                ans = max(ans , 1+m[arr[i] - difference]);
                m[arr[i]] = 1+m[arr[i]-difference];
            }
            else
            {
                m[arr[i]] = 1;
            }
        }
        return ans;
    }
};