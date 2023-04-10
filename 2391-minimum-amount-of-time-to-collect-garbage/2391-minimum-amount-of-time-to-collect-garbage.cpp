class Solution {
public:
    #define ll long long
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int ans=0;
        for(auto it : garbage)
        {
            ans += it.size();
        }
        vector<int> pref(travel.size()+1 , 0);
        for(int i=1;i<pref.size();i++)
        {
            pref[i] = pref[i-1]+travel[i-1];
        }
        int GIndex , PIndex , MIndex;
        bool g=0,p=0,m=0;
        for(int k=garbage.size()-1;k>=0;k--)
        {
            string s = garbage[k];
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='G' && !g)
                {
                    g=1;
                    GIndex=k;
                }
                if(s[i]=='P' && !p)
                {
                    p=1;
                    PIndex=k;
                }
                if(s[i]=='M' && !m)
                {
                    m=1;
                    MIndex=k;
                }
            }
            if(m && p && g)
            {
                break;
            }
        }
        if(p)
        {
            ans+=pref[PIndex];
        }
        if(m)
        {
            ans+=pref[MIndex];
        }
        if(g)
        {
            ans+=pref[GIndex];
        }
        return ans;
    }
};