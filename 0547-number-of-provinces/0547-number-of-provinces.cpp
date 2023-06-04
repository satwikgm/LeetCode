class Solution {
public:
    void fun(vector<int> adj[] , int s , bool visited[])
    {
        visited[s]=1;
        for(int i : adj[s])
        {
            if(!visited[i])
            {
                fun(adj,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }   
        bool visited[n];
        memset(visited,0,sizeof(visited));
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                c++;
                fun(adj,i,visited);
            }
        }
        return c;
    }
};