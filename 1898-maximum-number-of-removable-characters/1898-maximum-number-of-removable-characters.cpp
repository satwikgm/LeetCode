class Solution {
public:
    int rem[100001]={};
    bool hasSubsequence(string s , string p , vector<int> removables , int k)
    {
        memset(rem,0,sizeof(rem));
        for(int i=0;i<k;i++)
        {
            rem[removables[i]]=1;  // mark this index as removed
        }
        int n=s.size() , m=p.size() , j=0;
        for(int i=0;i<n && j<m;i++)
        {
            if(rem[i])
            {
                continue;
            }
            if(s[i] == p[j])
            {
                j++; 
            }
        }
        return j==m;  // if j reaches m => p exists in s even after removal
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        int l=0 , h=removable.size();
        int m , return_value;
        while(l<=h)
        {
            m=(l+h)/2;
            if(hasSubsequence(s,p,removable,m))
            {
                return_value=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        return return_value;
    }
};