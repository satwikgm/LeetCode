class StockSpanner {
public:
    vector<int> ans;
    // price idx
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(ans.size()==0) {
            ans.push_back(1);
            st.push({price,0});
            return 1;
        }
        int idx = ans.size();
        while(st.size() && st.top().first <= price) {
            st.pop();
        }        
        if(!st.size()) {
            ans.push_back(idx+1);
        } else {
            ans.push_back(idx - st.top().second);
        }
        st.push({price,idx});
        return ans.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */