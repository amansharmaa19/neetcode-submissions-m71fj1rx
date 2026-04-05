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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string serializedResult = "";
        queue<TreeNode*> q;
        serializedResult += to_string(root->val) + ",";
        q.push(root);
        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();
            if (front->left) {
                q.push(front->left);
                serializedResult += to_string(front->left->val) + ",";
            } else {
                serializedResult += "#,";
            }
            if (front->right) {
                q.push(front->right);
                serializedResult += to_string(front->right->val) + ",";
            } else {
                serializedResult += "#,";
            }
        }
        return serializedResult;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream ss(data);
        string str = "";
        getline(ss, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        int currentIndex = 0;
        int left = (2 * currentIndex) + 1;
        int right = (2 * currentIndex) + 2;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();

            getline(ss, str, ',');
            if (str != "#") {
                TreeNode *newNode = new TreeNode(stoi(str));
                front->left = newNode;
                q.push(newNode);
            }
            getline(ss, str, ',');
            if (str != "#") {
                TreeNode *newNode = new TreeNode(stoi(str));
                front->right = newNode;
                q.push(newNode);
            }
            currentIndex++;
            left = (2 * currentIndex) + 1;
            right = (2 * currentIndex) + 2;
        }
        return root;
    }
};
