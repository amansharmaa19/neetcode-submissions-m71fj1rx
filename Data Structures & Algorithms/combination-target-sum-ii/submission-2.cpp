class Solution {
public:
    void combinationUtil(
        int index,
        int target,
        vector<int>& candidates,
        vector<int>& eachCombination,
        vector<vector<int>>& combinations
    ) {
        if (target == 0) {
            combinations.push_back(eachCombination);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            eachCombination.push_back(candidates[i]);
            combinationUtil(
                i + 1,
                target - candidates[i],
                candidates,
                eachCombination,
                combinations
            );
            eachCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> eachCombination;
        vector<vector<int>> combinations;
        combinationUtil(0, target, candidates, eachCombination, combinations);
        return combinations;
    }
};
