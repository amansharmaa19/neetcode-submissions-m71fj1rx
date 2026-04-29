/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    void rightSideViewUtil(
        TreeNode* root,
        int currLevel,
        int& maxLevel,
        vector<int>& result
    ) {
        if (root == nullptr) {
            return;
        }
        if (maxLevel < currLevel) {
            maxLevel = currLevel;
            result.push_back(root->val);
        }
        rightSideViewUtil(root->right, currLevel + 1, maxLevel, result);
        rightSideViewUtil(root->left, currLevel + 1, maxLevel, result);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int maxLevel = -1;
        rightSideViewUtil(root, 0, maxLevel, result);
        return result;
    }
};
