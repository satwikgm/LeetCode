class Solution {
public:
    bool fun(string s , int target)
    {
        if(s=="")
        {
            return target==0;
        }
        if(target<0)
        {
            return 0;
        }
        for(int i=0;i<s.size();i++)
        {
            string s1 = s.substr(0,i+1);
            string s2 = s.substr(i+1);
            if(fun(s2,target-stoi(s1)))
            {
                return 1;
            }
        }
        return 0;
    }
    int punishmentNumber(int n) 
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x = i*i;
            string s = to_string(x);
            if(fun(s  , i))
            {
                ans += x;
            }
        }
        return ans;
    }
};