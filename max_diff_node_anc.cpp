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
    void fun(TreeNode* root , int mx , int mn , int &ans)
    {
        if(!root)
        {
            return;
        }
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        ans = max(ans , mx-mn);
        fun(root->left,mx,mn,ans);
        fun(root->right,mx,mn,ans);
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        int ans=0;
        fun(root,INT_MIN,INT_MAX,ans);
        return ans;
    }
};
