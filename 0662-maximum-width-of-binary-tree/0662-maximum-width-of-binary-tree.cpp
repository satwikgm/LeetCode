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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        long long int res=0;
        while(!q.empty())
        {
            long long int count = q.size();
            long long int mn , mx;
            long long int x = q.front().second;
            for(long long int i=0;i<count;i++)
            {
                pair<TreeNode*,long long int> p = q.front();
                q.pop();
                TreeNode* curr = p.first;
                long long int data = p.second-x;
                if(i==0)
                {
                    mn = data;
                }
                if(i == count-1)
                {
                    mx = data;
                }
                if(curr->left)
                {
                    q.push({curr->left , 2*data+1});
                }
                if(curr->right)
                {
                    q.push({curr->right , 2*data+2});
                }
            }
            res=max(res,mx-mn);
        }    
        return res+1;   
    }
};