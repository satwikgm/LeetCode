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
    void fun(TreeNode* root,vector<int> &v)
    {
        if(!root)
        {
            return;
        }
        fun(root->left , v);
        v.push_back(root->val);
        fun(root->right , v);
    }
    int getMinimumDifference(TreeNode* root) 
    {
        int ans=INT_MAX;
        vector<int> v;
        fun(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            ans = min(ans , v[i+1]-v[i]);
        }
        return ans;
    }
};