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
    int pairSum(ListNode* head) {
        int len=0;
        int ans=0;
        stack<ListNode*> s;
        ListNode* curr=head;
        while(curr)
        {
            s.push(curr);
            curr=curr->next;
            len++;
        }
        curr=head;
        for(int i=0;i<len/2;i++)
        {
            auto node = s.top()->val;
            s.pop();
            ans = max(ans , node+curr->val);
            curr=curr->next;
        }
        return ans;
    }
};