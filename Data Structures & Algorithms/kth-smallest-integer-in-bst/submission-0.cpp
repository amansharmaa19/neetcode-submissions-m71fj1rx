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
    void kthSmallestUtil(TreeNode* root, int k, int &currentMax, int &kSmallestElement) {
        if (!root) {
            return;
        }
        kthSmallestUtil(root->left, k, currentMax, kSmallestElement);
        currentMax += 1;
        if (currentMax == k) {
            kSmallestElement = root->val;
        }
        kthSmallestUtil(root->right, k, currentMax, kSmallestElement);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int kSmallestElement = 0;
        int currentMax = 0;
        kthSmallestUtil(root, k, currentMax, kSmallestElement);
        return kSmallestElement;
    }
};
