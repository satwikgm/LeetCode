/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* fun(vector<int> &v , int l , int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int m = (l+r)/2;
        TreeNode* root = new TreeNode(v[m]);
        root->left = fun(v , l , m-1);
        root->right = fun(v , m+1 , r);
        return root; 
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(!head) {
            return NULL;
        }
        vector<int> v;
        ListNode* curr = head;
        while(curr) 
        {
            v.push_back(curr->val);
            curr = curr->next;
        }    
        return fun(v , 0 , v.size()-1);
    }
};