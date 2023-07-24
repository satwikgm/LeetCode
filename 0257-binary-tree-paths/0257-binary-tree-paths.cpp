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
    void fun(TreeNode* root , vector<string> &ans , string s)
    {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            if(s=="") {
                s += to_string(root->val);
            } else {
                s += "->";
                s += to_string(root->val);
            }
            ans.push_back(s);
            return;
        }
        if(s=="") {
            s += to_string(root->val);
        } else {
            s += "->";
            s += to_string(root->val);
        }
        if(root->left) {
            fun(root->left,ans,s);
        }
        if(root->right) {
            fun(root->right,ans,s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        fun(root,ans,"");
        return ans;
    }
};