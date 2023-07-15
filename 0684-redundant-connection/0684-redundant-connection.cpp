class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) 
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) 
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) 
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);   // path compression
                                            // bcoz returned value is stored
    }

    bool unionByRank(int u, int v) 
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // ultimate par of u=v so 
        if (ulp_u == ulp_v) return 0; // u and v are already in union(same ultimate parent so no need of union)
        if (rank[ulp_u] < rank[ulp_v]) 
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) 
        {
            parent[ulp_v] = ulp_u;
        }
        else        // same rank 
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return 1;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        DisjointSet ds(n);
        for(auto it : edges)
        {
            if(ds.unionByRank(it[0] - 1, it[1] - 1) == 0)
            {
                return it;
            }
        }
        return {};
    }
};