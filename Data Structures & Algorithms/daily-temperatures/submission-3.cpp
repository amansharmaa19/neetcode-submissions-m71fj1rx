class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int temperatureSize = temperatures.size();
        stack<int> st;
        vector<int> result(temperatureSize, 0);
        for (int i = temperatureSize - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if (st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i;
            }
            st.push(i);
        }
        return result;
    }
};
