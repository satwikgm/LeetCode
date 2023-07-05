/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        
        unordered_map<Node*,Node*> m;
        
        for(Node* curr = head;curr!=NULL;curr=curr->next)
        {
            Node* node = new Node(curr->val);
            m[curr] = node;
        }
                
        for(Node* curr = head;curr!=NULL;curr=curr->next)
        {
            auto node = m[curr];
            node->next = m[curr->next];
            node->random = m[curr->random];
        }
        
        
        return m[head];
    }
};