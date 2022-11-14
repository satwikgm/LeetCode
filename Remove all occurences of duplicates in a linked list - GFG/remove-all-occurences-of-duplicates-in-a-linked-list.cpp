//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

// } Driver Code Ends
//User function Template for C++

/* Linked List node structure
    
struct Node {
	int data;
	struct Node *next;
};

*/

class Solution
{
    public:
    Node* removeAllDuplicates(struct Node* head)
    {
        if(!head)
        {
            return NULL;
        }
        unordered_map<int,int> m;
        Node* curr = head;
        while(curr)
        {
            m[curr->data]++;
            curr=curr->next;
        }
        vector<int> v;
        curr=head;
        while(curr)
        {
            if(m[curr->data] == 1)
            {
                v.push_back(curr->data);
            }
            curr=curr->next;
        }
        if(v.size()==0)
        {
            return NULL;
        }
        Node* h = new Node(v[0]);
        curr = h;
        for(int i=1;i<v.size();i++)
        {
            curr->next = new Node(v[i]);
            curr=curr->next;
        }
        return h;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;


	while (T--)
	{
		int N;

		cin >> N ;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		Solution ob;
		head = ob.removeAllDuplicates(head);
		printList(head);

		cout << "\n";


	}
	return 0;
}

// } Driver Code Ends