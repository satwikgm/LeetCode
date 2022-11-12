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

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        if(!head || !head->next)
        {
            return head;
        }    
        vector<int> v;
        for(Node* curr = head ; curr != NULL ; curr = curr->next)
        {
            v.push_back(curr->data);
        }
        int i = m-1;
        int j = n-1;
        while(i<j)
        {
            swap(v[i++],v[j--]);
        }
        head = new Node(v[0]);
        Node* curr = head;
        for(int i=1;i<v.size();i++)
        {
            curr->next = new Node(v[i]);
            curr = curr->next;
        }
        return head;
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
		int N, m, n;
		cin >> N>>m>>n;

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

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends