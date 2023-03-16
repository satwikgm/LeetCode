class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> ans;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string x = words[i];
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                string y = words[j];
                if(y.find(x)!=-1)
                {
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};