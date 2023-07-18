//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

// DLL Node has two props : key and value
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key , int val)
    {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    Node* tail = new Node(0,0);
    Node* head = new Node(0,0);
    int cap;
    unordered_map<int,Node*> m;
    LRUCache(int cap)
    {
        this->cap=cap;  
        head->next = tail;
        tail->prev = head;
    }
    void insert(Node* node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        m[node->key] = node;
    }
    void remove(Node* node)
    {
        m.erase(node->key);
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int GET(int key)
    {
        if(m.find(key) == m.end())
        {
            return -1;
        }
        Node* node = m[key];
        remove(node);
        insert(node);
        return m[key]->val;
    }
    
    void SET(int key, int value)
    {
        Node* node = new Node(key,value);
        if(m.find(key)!=m.end())
        {
            remove(m[key]);
        }
        if(m.size()==cap)
        {
            remove(tail->prev);
        }
        insert(node);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends