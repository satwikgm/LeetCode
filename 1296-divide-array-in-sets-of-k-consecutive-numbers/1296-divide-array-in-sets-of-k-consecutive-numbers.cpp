class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n%k)
        {
            return 0;
        }
        map<int,int> m;
        for(auto it : nums)
        {
            m[it]++;
        }
        while(m.size())
        {
            auto ele = m.begin();
            auto elem = m.begin()->first;
            for(int i=0;i<k;i++)
            {
                if(m[elem+i] == 0)
                {
                    return 0;
                }
                m[elem+i]--;
                if(m[elem+i]==0)
                {
                    m.erase(elem+i);
                }
            }
        }
        return 1;
    }
};