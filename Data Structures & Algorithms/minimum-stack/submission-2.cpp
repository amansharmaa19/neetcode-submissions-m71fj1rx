class MinStack {
    stack<int> st;
    stack<int> stMin;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty() || val <= stMin.top()) {
            st.push(val);
            stMin.push(val);
        } else {
            st.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }
        if (st.top() == stMin.top()) {
            st.pop();
            stMin.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        if (st.empty()) {
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if (stMin.empty()) {
            return -1;
        }
        return stMin.top();
    }
};
