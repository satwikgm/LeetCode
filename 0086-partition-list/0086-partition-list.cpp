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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* left = new ListNode(0);
        ListNode* left_curr=left;
        ListNode* right = new ListNode(0);
        ListNode* right_curr=right;
        ListNode* curr=head;
        while(curr)
        {
            if(curr->val < x)
            {
                left_curr->next = curr;
                left_curr = left_curr->next;
            }
            else
            {
                right_curr->next = curr;
                right_curr = right_curr->next;
            }
            curr = curr->next;
        }
        left_curr->next = right->next;
        right_curr->next=NULL;
        return left->next;
    }
};