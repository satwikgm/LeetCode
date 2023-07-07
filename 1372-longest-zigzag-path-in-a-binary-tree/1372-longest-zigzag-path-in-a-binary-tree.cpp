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
    int ans=0;
    void fun(TreeNode* root , bool left , int steps)
    {
        ans=max(ans,steps);
        if(!root)
        {
            return;
        }
        if(left)
        {
            fun(root->right , 0 , steps+1);
            fun(root->left , 1 , 1);
        }
        else
        {
            fun(root->left , 1 , steps+1);
            fun(root->right , 0, 1);
        }
    }
    int longestZigZag(TreeNode* root) 
    {
        fun(root , 1 , 0);  // isleft
        fun(root , 0 , 0);  // isright
        return ans-1;
    }
};