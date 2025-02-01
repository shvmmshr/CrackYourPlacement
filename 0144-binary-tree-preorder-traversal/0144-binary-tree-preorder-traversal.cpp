class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        // Visit the root node
        result.push_back(node->val);
        // Traverse the left subtree
        preorderHelper(node->left, result);
        // Traverse the right subtree
        preorderHelper(node->right, result);
    }
};