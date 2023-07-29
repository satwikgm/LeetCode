class Solution {
public:
    vector<int> color;
    bool bfs(vector<vector<int>>& g , int s)
    {
        color[s]=0;
        queue<int> q;
        q.push(s);
        while(q.size())
        {
            auto node = q.front();
            q.pop();
            for(auto it : g[node])
            {
                if(color[it]==-1)
                {
                    if(color[node]==0)
                    {
                        color[it]=1;
                    }
                    else
                    {
                        color[it]=0;
                    }
                    q.push(it);
                }
                else
                {
                    if(color[it]==color[node])
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    bool isBipartite(vector<vector<int>>& g) {
        int v = g.size();
        color.resize(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(g,i))
                    return 0;
            }
        }
        return 1;
    }
};