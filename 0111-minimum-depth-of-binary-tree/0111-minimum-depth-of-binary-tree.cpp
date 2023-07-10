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
    int minDepth(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty())
        {
            int count=q.size();
            for(int j=0;j<count;j++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
                if(!curr->left && !curr->right)
                {
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};