class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        vector<int> arr;
        for(int i=0;i<s.size();i++)
        {
            arr.push_back(abs(s[i]-t[i]));
        }
        int i=0,j=0,ans=0,sum=0;
        while(j<arr.size())
        {
            sum += arr[j];
            while(sum > maxCost)
            {
                sum -= arr[i++];
            }
            if(sum <= maxCost)
            {
                ans = max(ans , j-i+1);
            }
            j++;
        }
        return ans;
    }
};