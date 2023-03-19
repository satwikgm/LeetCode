class Node {
public:
    Node* links[26];
    bool flag=false;
    
    bool hasKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }
    void put(char ch , Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++)
        {
            if(!curr->hasKey(word[i]))
            {
                curr->put(word[i] , new Node());
            }
            curr = curr->get(word[i]);
        }
        curr->setEnd();
    }
    
    bool helperSearch(string word , Node* curr)
    {
        for(int i=0;i<word.size();i++)
        {
            if(word[i] == '.')
            {
                for(char ch = 'a' ; ch <= 'z' ; ch++)
                {
                    if(curr->hasKey(ch) && helperSearch(word.substr(i+1) , curr->get(ch)))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if(!curr->hasKey(word[i]))
                {
                    return false;
                }
                curr = curr->get(word[i]);
            }
        }
        return curr->isEnd();
    }
    bool search(string word) {
        Node* curr = root;
        return helperSearch(word,curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */