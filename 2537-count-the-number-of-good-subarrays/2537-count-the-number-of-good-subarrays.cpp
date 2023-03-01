class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        long long ans=0 , k1=0;
        int i=0,j=0;
        unordered_map<int,int> m;
        while(j<nums.size())
        {
            m[nums[j]]++;
            k1 += m[nums[j]]-1;
            while(i<j && k1 >= k)
            {
                ans += nums.size()-j;
                m[nums[i]]--;
                k1 -= m[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};