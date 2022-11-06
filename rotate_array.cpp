class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k=k%n;
        reverse(nums.begin(),nums.begin()+n-k);             // Rotate first half
        reverse(nums.begin()+n-k,nums.end());              // Rotate second half
        reverse(nums.begin(),nums.end());                  // Rotate entire array 
    }
};
