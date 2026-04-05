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
    bool identicalTree(TreeNode *tree1, TreeNode *tree2) {
        if (!tree1 && !tree2) {
            return true;
        } else if (!tree1 || !tree2) {
            return false;
        } else if (tree1->val != tree2->val) {
            return false;
        }
        return identicalTree(tree1->left, tree2->left) &&
            identicalTree(tree1->right, tree2->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (identicalTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot);
    }
};
