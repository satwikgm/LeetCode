class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return nums;
        }
        
        sort(nums.begin(),nums.end());
        
        vector<int> lds(n,1);
        vector<int> m(n,0);
        
        for(int i=0;i<n;i++)
        {
            m[i]=i;
        }
    
        int mx=1 , ind=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && lds[i] < 1+lds[j])
                {
                    lds[i]=1+lds[j];
                    m[i]=j;
                }
            }
            if(lds[i] > mx)
            {
                mx=lds[i];
                ind=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[ind]);
        while(m[ind] != ind)
        {
            ind=m[ind];
            ans.push_back(nums[ind]);
        }
        return ans;
    }
};