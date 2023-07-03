class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s.size()!=goal.size())
        {
            return 0;
        }
        if(s==goal)
        {
            unordered_map<char,int> m;
            for(auto it : s)
            {
                m[it]++;
                if(m[it]>1)
                {
                    return 1;
                }
            }
            return 0;
        }
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != goal[i])
            {
                c++;
            }
        }
        if(c<=2)
        {
            sort(s.begin(),s.end());
            sort(goal.begin(),goal.end());
            return s==goal;
        }
        return 0;
    }
};