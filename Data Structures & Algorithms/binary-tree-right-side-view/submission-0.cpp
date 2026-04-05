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
public:
    void rightSideViewUtil(
        TreeNode *root,
        int currHeight,
        int &maxHeight,
        vector<int> &rightSideNodes
    ) {
        if (!root) { 
            return;
        }
        if (currHeight > maxHeight) {
            maxHeight = currHeight;
            rightSideNodes.push_back(root->val);
        }
        rightSideViewUtil(root->right, currHeight + 1, maxHeight, rightSideNodes);
        rightSideViewUtil(root->left, currHeight + 1, maxHeight, rightSideNodes);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideNodes;
        int maxHeight = -1;
        int currHeight = 0;
        rightSideViewUtil(root, currHeight, maxHeight, rightSideNodes);
        return rightSideNodes;
    }
};
