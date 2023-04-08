class Solution {
public:
    #define ll long long
    bool isPossible(vector<int>& target) 
    {
        priority_queue<ll> pq;
        ll sum = 0;
        for(int i=0;i<target.size();i++)
        {
            sum += target[i];
            pq.push(target[i]);
        }
        while(pq.top() != 1)
        {
            ll x = pq.top();
            pq.pop();
            sum -= x;
            if(x == 1 || sum == 1)
            {
                return 1;
            }
            if(x<sum || sum==0 || x%sum==0)
            {
                return 0;
            }
            x %= sum;
            sum += x;
            pq.push(x);
        }
        return 1;
    }
};