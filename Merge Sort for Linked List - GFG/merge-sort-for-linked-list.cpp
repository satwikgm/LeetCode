//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* findMid(Node* head) {
        Node* s = head , *f = head->next;
        while(f && f -> next) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    Node* merge(Node* l , Node* r) {
        if(!l) {
            return r;
        }
        if(!r) {
            return l;
        }
        Node* ans = new Node(-1);
        Node* curr = ans;
        while(l && r) {
            if(l->data > r->data) {
                curr->next = r;
                curr = r;
                r = r->next;
            }
            else {
                curr->next = l;
                curr = l;
                l = l->next;
            }
        }
        while(l) {
            curr->next = l;
            curr = l;
            l = l->next;
        }
        while(r) {
            curr->next = r;
            curr = r;
            r = r->next;
        }
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        if(!head || !head->next) {
            return head;
        }
        Node* mid = findMid(head);
        Node* l = head;
        Node* r = mid->next;
        mid->next = NULL;
        l = mergeSort(l);
        r = mergeSort(r);
        return merge(l,r);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends