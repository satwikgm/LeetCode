class Solution {
public:
    int longestBeautifulSubstring(string word) 
    {
        int len=1;
        int ctr=1;
        int ans=0;
        for(int i=1;i<word.size();i++)
        {
            if(word[i] == word[i-1])
            {
                len++;
            }
            else if(word[i] > word[i-1])
            {
                len++;
                ctr++;
            }
            else
            {
                len=1;
                ctr=1;
            }
            
            if(ctr==5)
            {
                ans = max(ans , len);
            }
        }
        return ans;
    }
};