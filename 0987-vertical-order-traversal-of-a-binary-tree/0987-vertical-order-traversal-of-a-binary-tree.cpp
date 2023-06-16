/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        // Node , hd , level
        queue<pair<TreeNode*,pair<int,int>>> q;
        // hd , level , Node->val
        map<int,map<int,multiset<int>>> m;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            auto node = p.first;
            int hd = p.second.first;
            int lev = p.second.second;
            m[hd][lev].insert(node->val);
            if(node->left)
            {
                q.push({node->left,{hd-1,lev+1}});
            }
            if(node->right)
            {
                q.push({node->right,{hd+1,lev+1}});
            }
        }
        for(auto i : m)
        {
            vector<int> v;
            for(auto j : i.second)
            {
                for(auto k : j.second)
                {
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};