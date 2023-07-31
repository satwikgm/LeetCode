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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
        {
            return head;
        }
        ListNode* o=head , *e=head->next;
        ListNode* eHead = e;
        ListNode* oHead = o;
        while(e && e->next)
        {
            o->next=e->next;
            o=e->next;
            e->next=o->next;
            e=o->next;
        }
        o->next = eHead;
        return oHead;
    }
};