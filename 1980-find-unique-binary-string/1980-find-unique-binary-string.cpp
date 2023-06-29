class Solution {
public:
    void fun(int str_size , string s , vector<string> &ans)
    {
        if(s.size() == str_size)
        {
            ans.push_back(s);
            return;
        }
        fun(str_size,s+'0',ans);
        fun(str_size,s+'1',ans);
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int str_size=nums[0].size();
        unordered_map<string,int> st;
        for(auto it : nums)
        {
            st[it]++;
        }
        vector<string> ans;
        fun(str_size,"",ans);
        for(int i=0;i<ans.size();i++)
        {
            if(st.find(ans[i]) == st.end())
                return ans[i];
        }
        return "";
    }
};