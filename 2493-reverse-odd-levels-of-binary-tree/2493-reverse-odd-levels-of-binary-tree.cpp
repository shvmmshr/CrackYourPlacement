class Solution {
public:
    void reverseValues(TreeNode* node1, TreeNode* node2, int level) {
        if (!node1 || !node2) return;
        if (level % 2 == 1) {
            swap(node1->val, node2->val);
        }
        reverseValues(node1->left, node2->right, level + 1);
        reverseValues(node1->right, node2->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        reverseValues(root->left, root->right, 1);
        return root;
    }
};
