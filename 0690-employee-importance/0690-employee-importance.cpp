/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) 
    {
        unordered_map<int,Employee*> m;
        for(auto it : employees)
        {
            m[it->id]=it;
        }
        queue<Employee*> q;
        q.push(m[id]);
        int ans=0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            ans += it->importance;
            for(auto iter : it->subordinates)
            {
                q.push(m[iter]);
            }
        }
        return ans;
    }
};