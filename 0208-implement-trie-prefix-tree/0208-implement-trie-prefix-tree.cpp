class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;
    TrieNode() {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        isLeaf = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++)
        {
            if(curr->children[word[i] - 'a' ] == NULL)
            {
                curr->children[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++)
        {
            if(!curr->children[word[i] - 'a'])
            {
                return false;
            }
            curr = curr->children[word[i]-'a'];
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!curr->children[prefix[i] - 'a'])
            {
                return false;
            }
            curr = curr->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */