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
    int diameterUtil(TreeNode* root, int& maxDiameter) {
        if (root == nullptr) {
            return 0;
        }
        int left = diameterUtil(root->left, maxDiameter);
        int right = diameterUtil(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, left + right);
        return max(left, right) + 1;
    } 
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        diameterUtil(root, maxDiameter);
        return maxDiameter;
    }
};
