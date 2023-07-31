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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        if(head->next && head->val==head->next->val)
        {
            while(head->next && head->val==head->next->val)
            {
                head=head->next;
            }
            if(head)
            {
                head=head->next;
            }
        }
        ListNode* curr=head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        while(curr)
        {
            if(curr->next && curr->val == curr->next->val)
            {
                while(curr->next && curr->val==curr->next->val)
                {
                    curr=curr->next;
                }
                prev->next=curr->next;
            }
            else
            {
                prev=curr;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};