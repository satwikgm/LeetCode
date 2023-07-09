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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        int top=0,bottom=m-1;
        int left=0,right=n-1;
        ListNode* curr=head;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                if(!curr)
                {
                    matrix[top][i]=-1;
                    continue;
                }
                matrix[top][i]=curr->val;
                curr=curr->next;
            }   
            top++;
            for(int i=top;i<=bottom;i++)
            {
                if(!curr)
                {
                    matrix[i][right]=-1;
                    continue;
                }
                matrix[i][right]=curr->val;
                curr=curr->next;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    if(!curr)
                    {
                        matrix[bottom][i]=-1;
                        continue;
                    }
                    matrix[bottom][i]=curr->val;
                    curr=curr->next;
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    if(!curr)
                    {
                        matrix[i][left]=-1;
                        continue;
                    }
                    matrix[i][left]=curr->val;
                    curr=curr->next;
                }
                left++;
            }
        }
        return matrix;
    }
};