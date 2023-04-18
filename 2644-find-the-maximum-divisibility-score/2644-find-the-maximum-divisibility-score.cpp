class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) 
    {
        vector<int> ans;
        for(int i=0;i<divisors.size();i++)
        {
            int c=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] % divisors[i] == 0)
                {
                    c++;
                }
            }
            ans.push_back(c);
        }
        int mx=0;
        int mxi=0;
        int ret=divisors[0];
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i] > mx)
            {
                mx = ans[i];
                mxi = i;
                ret = divisors[i];
            }
            if(ans[i] == mx)
            {
                ret = min(ret , divisors[i]);
            }
        }
        return ret;
    }
};