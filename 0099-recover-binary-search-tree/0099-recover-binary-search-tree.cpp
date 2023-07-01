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
    TreeNode* f = NULL , *m = NULL , *l = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            if(prev->val > root->val)
            {
                if(!f)
                {
                    f = prev;
                    m = root;
                }
                else
                {
                    l = root;
                }
            }
            prev=root;
            inorder(root->right);
        }
    }
    void swap(TreeNode* a , TreeNode* b)
    {
        int t=a->val;
        a->val=b->val;
        b->val=t;
    }
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        if(f && l)
        {
            swap(f,l);
        }
        else
        {
            swap(f,m);
        }
    }
};