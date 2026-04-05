class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            int num = i;
            while (num >= 1) {
                if (num % 2 == 1) {
                    count++;
                }
                num /= 2;
            }
            result.push_back(count);
        }
        return result;
    }
};
