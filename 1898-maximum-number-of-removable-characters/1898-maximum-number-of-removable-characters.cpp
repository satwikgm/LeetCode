class Solution {
public:
    bool hasSubsequence(string s , string p)
    {
        int j=p.size()-1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] == p[j])
            {
                j--;
            }
            if(j<0)
            {
                return 1;
            }
        }
        return j<0;
    }
    string removeElements(string s , vector<int> &removables , int idx)
    {
        unordered_set<int> st;
        for(int i=0;i<idx;i++)
        {
            st.insert(removables[i]);
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(st.find(i) == st.end())
            {
                ans+=s[i];
            }
        }
        return ans;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        int l=0 , h=removable.size();
        int m , ans;
        while(l<=h)
        {
            m=(l+h)/2;
            string ans = removeElements(s,removable,m);
            if(hasSubsequence(ans,p))
            {
                ans=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        return h;
    }
};