class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        vector<int> color(n,0);
        int ctr=0;
        for(int i=0;i<queries.size();i++)
        {
            if(i>0)
            {
                ctr = ans[i-1];
            }
            
            int idx = queries[i][0];
            int clr = queries[i][1];
            
            if(idx-1>=0)
            {
                if(color[idx] && color[idx-1]==color[idx])
                {
                    ctr--;
                }
            }
            
            if(idx+1<n)
            {
                if(color[idx] && color[idx+1]==color[idx])
                {
                    ctr--;
                }
            }
            
            color[idx] = clr;
            
            
            if(idx-1>=0)
            {
                if(color[idx] && color[idx-1]==color[idx])
                {
                    ctr++;
                }
            }
            
            if(idx+1<n)
            {
                if(color[idx] && color[idx+1]==color[idx])
                {
                    ctr++;
                }
            }
            
            
            ans.push_back(ctr);
        }
        
        return ans;
    }
};