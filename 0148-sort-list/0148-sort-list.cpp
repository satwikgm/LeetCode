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
    ListNode* mergeList(ListNode* l1 , ListNode* l2)
    {
        ListNode* ptr = new ListNode(-1);
        ListNode* curr=ptr;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                curr->next = l2;
                l2=l2->next;
            }
            else
            {
                curr->next = l1;
                l1=l1->next;
            }
            curr=curr->next;
        }
        if(l1)
        {
            curr->next = l1;
            // l1=l1->next;
        }
        if(l2)
        {
            curr->next=l2;
            // l2=l2->next;
        }
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode *s=head,*f=head,*prev;
        while(f && f->next)
        {
            prev=s;
            s=s->next;
            f=f->next->next;
        }
        prev->next=NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(s);
        return mergeList(l1,l2);
    }
};