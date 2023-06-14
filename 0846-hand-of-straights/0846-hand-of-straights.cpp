class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();
        if(n%groupSize)
        {
            return 0;
        }
        map<int,int> m;
        for(auto it : hand)
        {
            m[it]++;
        }
        while(m.size())
        {
            auto ele = m.begin();
            int elem = m.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(m[elem + i] <= 0)
                {
                    return 0;
                }
                m[elem+i]--;
                if(m[elem+i] == 0)
                {
                    m.erase(elem+i);
                }
            }
        }
        return 1;
    }
};