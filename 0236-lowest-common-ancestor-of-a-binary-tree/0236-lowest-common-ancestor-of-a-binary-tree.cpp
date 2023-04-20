/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pathToNode(TreeNode* root , TreeNode* node , vector<TreeNode*> &path)
    {
        if(!root)
        {
            return false;
        }
        path.push_back(root);
        if(root == node)
        {
            return 1;
        }
        if((root->left && pathToNode(root->left,node,path)) || (root->right && pathToNode(root->right,node,path)))
        {
            return 1;
        }
        path.pop_back();        // Backtrack
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> path1,path2;
        bool x = pathToNode(root,p,path1);
        bool y = pathToNode(root,q,path2);
        if(!x || !y)
        {
            return NULL;
        }
        TreeNode* lca=NULL;
        int i;
        for(i=0;i<min(path1.size() , path2.size());i++)
        {
            if(path1[i] != path2[i])
            {
                lca=path1[i-1];
                break;
            }
        }
        if(!lca)
        {
            if(path1.size() <= path2.size())
            {
                lca=path1[i-1];
            }
            else
            {
                lca=path2[i-1];
            }
        }
        return lca;
    }
};