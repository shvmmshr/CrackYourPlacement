class Solution {
public:
    int diameter(TreeNode* root, int &maxDiameter) {
        if (root == nullptr) {
            return 0;
        }
        int left = diameter(root->left, maxDiameter);
        int right = diameter(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        diameter(root, maxDiameter);
        return maxDiameter;
    }
};
