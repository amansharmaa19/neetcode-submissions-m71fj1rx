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
    bool isSameTreeUtil(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if ((!p && q) || (p && !q)) {
            return false;
        } else if (p->val != q->val) {
            return false;
        }
        bool isLeftValid = isSameTreeUtil(p->left, q->left);
        bool isRightValid = isSameTreeUtil(p->right, q->right);
        return isLeftValid && isRightValid;
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeUtil(p, q);
    }
};
