class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if(n==0)
        {
            return tasks.size();
        }
        unordered_map<char,int> m;
        int mx=0;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        for(auto it : m)
        {
            mx=max(mx,it.second);
        }
        int ans=(mx-1)*(n+1);
        for(auto it : m)
        {
            if(it.second==mx)
            {
                ans++;
            }
        }
        int k=tasks.size();
        return max(ans,k);
    }
};