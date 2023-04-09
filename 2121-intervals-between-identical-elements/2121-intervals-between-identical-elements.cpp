class Solution {
public:
    #define ll long long
    vector<long long> getDistances(vector<int>& arr) 
    {
        int n=arr.size();
        vector<ll> ans(n,0);
        unordered_map<ll,ll> sum_total_ind , sum_prev_ind ,  total_count , prev_count;
        
        for(int i=0;i<n;i++)
        {
            total_count[arr[i]]++;
            prev_count[arr[i]]=0;
            
            sum_total_ind[arr[i]] += i;
            sum_prev_ind[arr[i]] = 0;
        }
        
        for(int i=0;i<n;i++)
        {
            ans[i] = (i*prev_count[arr[i]]  -  sum_prev_ind[arr[i]] )   +    (  sum_total_ind[arr[i]]  -  sum_prev_ind[arr[i]]  - i  - (i*( total_count[arr[i]] - 1 - prev_count[arr[i]]  )  )   ) ;
            
            prev_count[arr[i]]++;
            sum_prev_ind[arr[i]] += i;
        }
        
        return ans;
    }
};