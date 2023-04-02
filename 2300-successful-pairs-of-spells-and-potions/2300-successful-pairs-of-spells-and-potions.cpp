class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++)
        {
            long long x=spells[i];
            bool fl=0;
            int l=0,h=potions.size()-1;
            int ind;
            while(l<=h)
            {
                int m=(l+h)/2;
                if(x*(long long)potions[m] >= success)
                {
                    ind=m;
                    fl=1;
                    h=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
            
            if(fl==0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(potions.size()-ind);
            }
        }
        return ans;
    }
};