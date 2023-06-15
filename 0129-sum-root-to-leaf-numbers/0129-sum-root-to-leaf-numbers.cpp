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
    void fun(vector<string> &ans , TreeNode* root , string p)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right)
        {
            p+=to_string(root->val);
            ans.push_back(p);
            return;
        }
        p += to_string(root->val);
        fun(ans , root->left , p);
        fun(ans , root->right , p);
    }
    int sumNumbers(TreeNode* root) 
    {
        vector<string> ans;
        fun(ans,root,"");
        int ans_sum=0;
        for(int i=0;i<ans.size();i++)
        {
            ans_sum += stoi(ans[i]);
        }
        return ans_sum;
    }
};