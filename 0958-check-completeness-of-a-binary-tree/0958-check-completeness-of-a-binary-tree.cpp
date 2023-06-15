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
    bool isCompleteTree(TreeNode* root) 
    {
        if(!root)
        {
            return 1;
        }
        bool flag=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count = q.size();
            for(int i=0;i<count;i++)
            {
                auto node = q.front();
                q.pop();
                if(node->left)
                {
                    if(flag)
                    {
                        return 0;
                    }
                    else
                    {
                        q.push(node->left);
                    }
                }
                else
                {
                    flag=1;
                }
                
                if(node->right)
                {
                    if(flag)
                    {
                        return 0;
                    }
                    else
                    {
                        q.push(node->right);
                    }
                }
                else
                {
                    flag=1;
                }
            }
        }
        return 1;
    }
};