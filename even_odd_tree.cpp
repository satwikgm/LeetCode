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
    bool isEvenOddTree(TreeNode* root) 
    {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count = q.size();
            int mn = INT_MIN;
            int mx = INT_MAX;
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(level % 2 == 0)
                {
                    if(curr->val % 2 == 0 || curr->val <= mn)
                    {
                        return false;
                    }
                    mn = curr->val;
                }
                else
                {
                    if(curr->val % 2 == 1 || curr->val >= mx)
                    {
                        return false;
                    }
                    mx = curr->val;
                }
                if(curr->left) 
                {
                    q.push(curr->left);
                }
                if(curr->right) 
                {
                    q.push(curr->right);
                }
            }
            level++;
        }    
        return true;
    }
};
