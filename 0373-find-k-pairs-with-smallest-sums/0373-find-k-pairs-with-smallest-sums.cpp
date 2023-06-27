class Solution {
public:
    #define pi pair<int,vector<int>>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)     {
        priority_queue<pi> pq;
        bool fl=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k)
                {
                    pq.push({sum,{nums1[i] , nums2[j]}});
                }
                else if(sum < pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i] , nums2[j]}});
                }
                else
                {
                    if(j==0)
                    {
                        fl=1;
                    }
                    break;
                }
            }
            if(fl)
            {
                break;
            }
        }
        vector<vector<int>> ans;
        while(pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};