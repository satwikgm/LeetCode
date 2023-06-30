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
    unordered_map<TreeNode*,TreeNode*> parent;
    TreeNode* target;
    void findParent(TreeNode* root , int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node->val == start)
            {
                target=node;
            }
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
    int amountOfTime(TreeNode* root, int start) 
    {
        // Find Node with value start and parent nodes
        int ans=0;
        findParent(root,start);
        unordered_map<TreeNode*,int> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        while(q.size())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(parent[node] && !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
            }
            ans++;
        }
        return ans-1;
    }
};