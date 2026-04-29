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
    void kthSmallestUtil(TreeNode* root, int k, int& count, int& kthElement) {
        if (root == nullptr) {
            return;
        }
        kthSmallestUtil(root->left, k, count, kthElement);
        count++;
        if (count == k) {
            kthElement = root->val;
        }
        kthSmallestUtil(root->right, k, count, kthElement);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        int kthElement = -1;
        int count = 0;
        kthSmallestUtil(root, k, count, kthElement);
        return kthElement;
    }
};
