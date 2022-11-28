class BrowserHistory {
public:
    list<string> his;
    list<string> :: iterator it;
    BrowserHistory(string homepage) {
        his.push_back(homepage);
        it = his.begin();
    }
    
    void visit(string url) {
        list<string> :: iterator del = it;
        del++;
        his.erase(del , his.end());
        his.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(steps-- && it != his.begin()) {
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(steps--) {
            list<string> :: iterator k = it;
            if(++k == his.end())
            {
                return *it;
            }
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
