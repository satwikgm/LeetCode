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
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int s,int e,int &n) 
    {
        if(s>e)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[n--]);
        int i;
        for(i=s;i<=e;i++)
        {
            if(inorder[i]==root->val)
            {
                break;  
            }
        }
        root->right = build(inorder,postorder,i+1,e,n);
        root->left = build(inorder,postorder,s,i-1,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int s=0 , e=inorder.size();
        int ps = postorder.size()-1;
        return build(inorder,postorder,s,e-1,ps);
    }
};