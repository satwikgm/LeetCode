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
class BSTIterator {
public:
    vector<int> v;
    int i;
    void fun(TreeNode* root , vector<int> &arr)
    {
        if(root)
        {
            fun(root->left , arr);
            arr.push_back(root->val);
            fun(root->right , arr);
        }
    }
    BSTIterator(TreeNode* root) 
    {
        fun(root,v);
        i=-1;
    }
    
    int next() 
    {
        i++;
        return v[i];
    }
    
    bool hasNext() 
    {
        if(i+1<v.size())
        {
            return 1;
        }
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */