class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) 
    {
        if(rungs.size()==1)
        {
            if(rungs[0] <= dist)
            {
                return 0;
            }
            return (rungs[0]-1)/dist ;
        }
        int i;
        rungs.insert(rungs.begin(),0);
        i=0;
        int ans=0;
        while(i<rungs.size()-1)
        {
            if(rungs[i+1]-rungs[i] <= dist)
            {
                i++;
                continue;
            }
            ans += (rungs[i+1]-rungs[i]-1)/dist;
            i++;
        }
        return ans;
    }
};