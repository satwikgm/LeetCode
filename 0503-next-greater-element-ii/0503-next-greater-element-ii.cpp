class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr, int n)
    {
        stack<int> s; s.push(arr[n-1]);
        vector<int> ans; ans.push_back(-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && arr[i]>=s.top())
            {
                s.pop();
            }
            if(s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        vector<int> ans;
        vector<int> v = nextLargerElement(nums,nums.size());
        for(int i=0;i<n;i++)
        {
            ans.push_back(v[i]);
        }
        return ans;
    }
};