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
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        bool leftMost=0;
        int res=root->val;
        while(!q.empty())
        {
            int count = q.size();
            leftMost=0;
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                    if(!leftMost)
                    {
                        res = curr->left->val;
                        leftMost=1;
                    }
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    if(!leftMost)
                    {
                        res = curr->right->val;
                        leftMost=1;
                    }
                }
            }
        }    
        return res;
    }
};
