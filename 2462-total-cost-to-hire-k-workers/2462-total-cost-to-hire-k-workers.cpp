class Solution {
public:
    #define ll long long
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2;
        int n=costs.size();
        ll ans=0;
        int i=0,j=n-1,c=0;
        while(c<k)
        {
            while(pq1.size() < candidates && i<j)
            {
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size() < candidates && j>=i)
            {
                pq2.push(costs[j]);
                j--;
            }
            int el1=1e9;
            int el2=1e9;
            if(pq1.size())
            {
                el1=pq1.top();
            }
            if(pq2.size())
            {
                el2=pq2.top();
            }
            if(el1 <= el2)
            {
                ans += el1;
                pq1.pop();
            }
            else 
            {
                ans += el2;
                pq2.pop();
            }
            c++;
        }
        return ans;
    }
};