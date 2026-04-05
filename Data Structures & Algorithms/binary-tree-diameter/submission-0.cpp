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
    int height(TreeNode *root, int &maxDiameter) {
        if (!root) { 
            return 0;
        }
        int leftHeight = height(root->left, maxDiameter);
        int rightHeight = height(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        height(root, maxDiameter);
        return maxDiameter;
    }
};
