class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> in(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(int it : adj[i])
            {
                in[it]++;
            }
        }
        int ans=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            auto node = q.front();
            q.pop();
            ans++;
            for(auto it : adj[node])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }
        cout<<ans;
        return (ans==numCourses);
    }
};