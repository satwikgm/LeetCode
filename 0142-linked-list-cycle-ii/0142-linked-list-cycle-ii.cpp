/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head)
        {
            return NULL;
        }
        ListNode *s=head , *f=head;
        while(f && f->next)
        {
            s = s->next;
            f = f->next->next;
            if(s == f)
            {
                break;
            }
        }    
        if(s!=f)
        {
            return NULL;
        }
        if(s==f && s->next==NULL && f->next==NULL)
        {
            return NULL;
        }
        s=head;
        while(s!=f)
        {
            s=s->next;
            f=f->next;
        }
        return f;
    }
};