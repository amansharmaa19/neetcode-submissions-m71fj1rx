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
    void invertTreeUtil(TreeNode* root, TreeNode* newRoot) {
        if (root == nullptr) {
            return;
        } 
        if (root->left) {
            newRoot->right = new TreeNode(root->left->val);
        }
        if (root->right) {
            newRoot->left = new TreeNode(root->right->val);
        }
        invertTreeUtil(root->left, newRoot->right);
        invertTreeUtil(root->right, newRoot->left);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* newRoot = new TreeNode(root->val);
        invertTreeUtil(root, newRoot);
        return newRoot;
    }
};
