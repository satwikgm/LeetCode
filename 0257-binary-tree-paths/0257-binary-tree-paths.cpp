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
    void fun(vector<string> &ans , string curr , TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            ans.push_back(curr);
            return;
        }
        if(root->left)
        {
            fun(ans , curr + "->" +to_string(root->left->val) , root->left);
        }
        if(root->right)
        {
            fun(ans , curr + "->" + to_string(root->right->val) , root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        string curr;
        curr += to_string(root->val);
        fun(ans,curr,root);
        return ans;
    }
};