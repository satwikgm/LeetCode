//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head)
    {
        Node *curr=head , *next , *prev=NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(!first)
        {
            return second;
        }
        if(!second)
        {
            return first;
        }
        Node* head1 = reverse(first);
        Node* head2 = reverse(second);
        Node* curr1 = head1;
        Node* curr2 = head2;
        int c=0;
        Node* head=NULL;
        Node* curr;
        while(curr1 || curr2 || c)
        {
            if(curr1 && curr2)
            {
                c += curr1->data+curr2->data; 
                curr1=curr1->next;
                curr2=curr2->next;
            }
            else if(curr1)
            {
                c+=curr1->data;
                curr1=curr1->next;
            }
            else if(curr2)
            {
                c+=curr2->data;
                curr2=curr2->next;
            }
            Node* newNode = new Node(c%10);
            if(!head)
            {
                head = newNode;
                curr = head;
            }
            else
            {
                curr->next = newNode;
                curr = newNode;
            }
            c = c/10;
        }       
        return reverse(head);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends