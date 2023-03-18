class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> freq(nums.size(),0);
        fun(ans,v,nums,freq);
        return ans;
    }
private:
    void fun(vector<vector<int>> &ans , vector<int> &v , vector<int> &nums , vector<int> &freq)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                v.push_back(nums[i]);
                freq[i]=1;
                fun(ans,v,nums,freq);
                freq[i]=0;
                v.pop_back();
            }
        }
    }
    
};