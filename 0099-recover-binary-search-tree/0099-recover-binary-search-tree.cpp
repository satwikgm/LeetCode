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
    vector<TreeNode*> in;
    void inord(TreeNode* root)
    {
        if(root)
        {
            inord(root->left);
            in.push_back(root);
            inord(root->right);
        }
    }
    void swap(TreeNode* a , TreeNode* b)
    {
        int t = a->val;
        a->val=b->val;
        b->val=t;
    }
    void recoverTree(TreeNode* root) 
    {
        inord(root);
        bool fl=0;
        int ind1;
        int ind2;
        for(int i=0;i<in.size()-1;i++)
        {
            if(in[i]->val > in[i+1]->val)
            {
                if(fl)
                {
                    ind2=i+1;
                    break;
                }
                else
                {
                    ind1=i;
                    ind2=i+1;
                    fl=1;
                }
            }
        }
        if(fl)
        {
            swap(in[ind1],in[ind2]);
        }
        else
        {
            swap(in[ind1] , in[ind2]);
        }
    }
};