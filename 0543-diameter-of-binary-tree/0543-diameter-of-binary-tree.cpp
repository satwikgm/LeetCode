class Solution {
public:
    int ans=0;
    int height(TreeNode* root)
    {
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        int temp = 1+max(l,r);
        int temp_res = 1+l+r;
        ans = max(ans , temp_res);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        height(root);
        return ans-1;
    }
};