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
    int fun(TreeNode* root , int &ans)
    {
        if(!root)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            return root->val;
        }
        int l = fun(root->left,ans);
        int r = fun(root->right,ans);
        ans += abs(l-r);
        return l+r+root->val;
    }
    int findTilt(TreeNode* root) 
    {
        int ans=0;
        fun(root,ans);
        return ans;
    }
};