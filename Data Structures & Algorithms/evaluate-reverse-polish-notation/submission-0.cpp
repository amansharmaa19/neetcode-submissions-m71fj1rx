class Solution {
    stack<int> st;
public:
    int evalRPN(vector<string>& tokens) {
        for (const auto& character : tokens) {
            if (character == "+") {
                int second = 0;
                int first = 0;
                if (!st.empty()) {
                    second = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    first = st.top();
                    st.pop();
                }
                st.push(first + second);
            } else if (character == "-") {
                int second = 0;
                int first = 0;
                if (!st.empty()) {
                    second = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    first = st.top();
                    st.pop();
                }
                st.push(first - second);
            } else if (character == "/") {
                int second = 0;
                int first = 0;
                if (!st.empty()) {
                    second = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    first = st.top();
                    st.pop();
                }
                st.push(first / second);
            } else if (character == "*") {
                int second = 0;
                int first = 0;
                if (!st.empty()) {
                    second = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    first = st.top();
                    st.pop();
                }
                st.push(first * second);
            } else {
                st.push(stoi(character));
            }
        }
        return st.empty() ? -1 : st.top();
    }
};
