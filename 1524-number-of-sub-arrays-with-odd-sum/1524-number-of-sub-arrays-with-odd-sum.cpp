class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        long long mod = 1000000007;
        int n = arr.size();
        long long tot_sub = (n%mod)*((n+1)%mod)/2;
        unordered_map<int,int> m;
        m[0]=1;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            sum %= 2;
            ans += m[sum];
            m[sum]++;
        }
        return (tot_sub - ans)%mod;
    }
};