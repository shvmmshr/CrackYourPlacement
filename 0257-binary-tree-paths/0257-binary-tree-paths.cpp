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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root == NULL) return paths;
        if (root->left == NULL && root->right == NULL) {
            paths.push_back(to_string(root->val));
            return paths;
        }
        vector<string> leftPaths = binaryTreePaths(root->left);
        for (string path : leftPaths) {
            paths.push_back(to_string(root->val) + "->" + path);
        }
        vector<string> rightPaths = binaryTreePaths(root->right);
        for (string path : rightPaths) {
            paths.push_back(to_string(root->val) + "->" + path);
        }
        return paths;
    }
};