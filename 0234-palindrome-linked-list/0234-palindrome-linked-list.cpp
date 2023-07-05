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
    ListNode* revList(ListNode* h)
    {
        if(!h)
        {
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* curr=h;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode* s=head,*f=head;
        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
        }
        if(f)
        {
            s=s->next;
        }
        ListNode* rev = revList(s);
        ListNode* curr = head;
        while(rev)
        {
            if(curr->val != rev->val)
            {
                return 0;
            }
            curr=curr->next;
            rev=rev->next;
        }
        return 1;
    }
};