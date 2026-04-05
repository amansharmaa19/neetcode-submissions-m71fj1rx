class Solution {
    bool isValidBSTUtil(TreeNode *root, long minVal, long maxVal) {
        if (!root) { 
            return true;
        }
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        return isValidBSTUtil(root->left, minVal, root->val) &&
            isValidBSTUtil(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, INT_MIN, INT_MAX);
    }
};