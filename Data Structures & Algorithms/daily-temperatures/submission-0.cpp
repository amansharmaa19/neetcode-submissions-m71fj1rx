class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int temperatureSize = temperatures.size();
        vector<int> result(temperatureSize, 0);
        for (int i = 0; i < temperatureSize; i++) {
            int count = 0;
            bool found = false;
            for (int j = i; j < temperatureSize; j++) {
                if (temperatures[j] > temperatures[i]) {
                    found = true;
                    break;
                }
                count++;
            }
            if (found) {
                result[i] = count;
            } else {
                result[i] = 0;
            }
        }
        return result;
    }
};
