class StockSpanner {
    stack<pair<int, int>> st;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        int result = 0;
        while (!st.empty() && price >= st.top().first) {
            st.pop();
        }
        if (st.empty()) {
            result = index + 1;
        } else {
            result = index - st.top().second;
        }
        st.push({price, index});
        index++;
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */