class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key , int val)
    {
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class LRUCache {
public:
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    int cap;
    unordered_map<int,Node*> m;
    LRUCache(int capacity) {
        this->cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    // insert at begin
    void insert(Node* node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        m[node->key]=node;
    }
    // remove from last
    void remove(Node* node)
    {
        m.erase(node->key);
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    int get(int key) 
    {
        if(m.find(key)==m.end())
        {
            return -1;
        }
        Node* node = m[key];
        remove(node);
        insert(node);
        return m[key]->val;
    }
    
    void put(int key, int value) 
    {
        if(m.find(key) != m.end())
        {
            remove(m[key]);
        }
        Node* newNode = new Node(key,value);
        if(m.size()==cap)
        {
            remove(tail->prev);
        }
        insert(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */