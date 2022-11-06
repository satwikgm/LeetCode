class Solution {
public:
    string orderlyQueue(string s, int k) 
    {
        if(k>1)
        {
            sort(s.begin(),s.end());
        }    
        else
        {
            string ans=s;
            for(int i=0;i<s.size()-1;i++)
            {
                string r=s.substr(1,s.size()-1);
                r.push_back(s[0]);
                ans=min(ans,r);
                s=r;
            }
            return ans;
        }
        return s;
    }
};
