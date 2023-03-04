class Solution {
public:
    unordered_map<int,int> m;
    int integerReplacement(int n) 
    {
        if(n==1)
        {
            return 0;
        }
        if(m.find(n)==m.end())
        {
            if(n%2==0)
            {
                return m[n] = 1+integerReplacement(n/2);
            }
            else
            {
                return m[n] = 1+min(integerReplacement(n-1) , 1+integerReplacement(n/2+1));
            }
        }
        return m[n];
    }
};