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
    void fun(TreeNode* root , vector<int> &temp , vector<vector<int>> &ans , int target)
    {
        if(!root)
        {
            return;
        }
        temp.push_back(root->val);
        if(!root->left && !root->right && target == root->val)
        {
            ans.push_back(temp);
        }
        fun(root->left , temp , ans , target-root->val);
        fun(root->right , temp , ans , target-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(root , temp , ans , targetSum);
        return ans;
    }
};