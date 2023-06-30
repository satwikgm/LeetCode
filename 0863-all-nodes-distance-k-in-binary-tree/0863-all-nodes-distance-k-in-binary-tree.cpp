/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
                   // Child  Parent
    unordered_map<TreeNode*,TreeNode*> parent;
    void findParent(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right)
            {
                q.push(node->right);
                parent[node->right]=node;
            }
        }
    }
    unordered_map<TreeNode*,int> vis;
    void fun(TreeNode* t , vector<int> &ans , int k)
    {
        if(k==0)
        {
            ans.push_back(t->val);
            return;
        }
        vis[t]=1;
        if(t->left)
        {
            if(vis.find(t->left) == vis.end())
            {
                vis[t->left]=1;
                fun(t->left , ans , k-1);
            }
        }
        if(t->right)
        {
            if(vis.find(t->right) == vis.end())
            {
                vis[t->right]=1;
                fun(t->right , ans , k-1);
            }
        }
        if(parent[t])
        {
            if(vis.find(parent[t]) == vis.end())
            {
                vis[parent[t]]=1;
                fun(parent[t] , ans , k-1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int> ans;
        findParent(root);
        fun(target,ans,k);
        return ans;
    }
};