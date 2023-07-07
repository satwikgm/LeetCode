class Solution {
public:
    int fun(string s , int k , char ch)
    {
        int i=0;
        int kt=0;
        int ans=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]==ch)
            {
                
            }
            else
            {
                kt++;
            }
            while(kt > k)
            {
                if(s[i]!=ch)
                {
                    kt--;
                }
                i++;
            }
            ans = max(ans , j-i+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        return max(fun(answerKey , k , 'T'),fun(answerKey , k , 'F'));
    }
};