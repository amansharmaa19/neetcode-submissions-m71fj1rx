class Solution {
public:
    int calPoints(vector<string>& operations) {
        if (operations.size() == 0) {
            return 0;
        }
        int totalSum = 0;
        stack<int> st;
        for (int i = 0; i < operations.size(); i++) {
            string val = operations[i];
            if (val == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (val == "D") {
                if (!st.empty()) {
                    st.push(st.top() * 2);
                }
            } else if (val == "+") {
                if (!st.empty()) {
                    int first = st.top();
                    int second = 0;
                    st.pop();
                    if (!st.empty()) {
                        second = st.top();
                    }
                    st.push(first);
                    st.push(first + second);
                }
            } else {
                st.push(stoi(val));
            }
        }
        while (!st.empty()) {
            totalSum += st.top();
            st.pop();
        }
        return totalSum;
    }
};