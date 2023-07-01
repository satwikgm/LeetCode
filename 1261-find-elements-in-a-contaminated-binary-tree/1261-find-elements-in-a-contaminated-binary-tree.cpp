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
class FindElements {
public:
    TreeNode* r = new TreeNode(-1);
    set<int> s;
    FindElements(TreeNode* root) 
    {
        r = root;
        r->val = 0;
        fun(r);
        s.insert(0);
    }
    
    void fun(TreeNode* root)
    {
        if(root->left)
        {
            root->left->val = 2*(root->val)+1;
            s.insert(2*(root->val)+1);
            fun(root->left);
        }
        if(root->right)
        {
            root->right->val = 2*(root->val)+2;
            s.insert(2*(root->val)+2);
            fun(root->right);
        }
    }
    
    bool find(int target) 
    {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */