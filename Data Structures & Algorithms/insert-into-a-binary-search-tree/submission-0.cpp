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
    void insertUtil(TreeNode* root, int val) {
        if (!root) { 
            return;
        }
        if (val < root->val) {
            if (root->left) {
                insertUtil(root->left, val);
            } else {
                root->left = new TreeNode(val);
                return;
            }
        } else if (val > root->val) {
            if (root->right) {
                insertUtil(root->right, val);
            } else {
                root->right = new TreeNode(val);
                return;
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        insertUtil(root, val);
        return root;
    }
};