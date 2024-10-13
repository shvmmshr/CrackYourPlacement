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
    vector<int> perfectSubtreeSizes;
    pair<int, bool> dfs(TreeNode* root) {
        if (!root) return {0, true};
        auto [leftSize, isLeftPerfect] = dfs(root->left);
        auto [rightSize, isRightPerfect] = dfs(root->right);
        if (isLeftPerfect && isRightPerfect && leftSize == rightSize) {
            int totalSize = leftSize + rightSize + 1;
            perfectSubtreeSizes.push_back(totalSize);
            return {totalSize, true};
        }
        return {0, false};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        perfectSubtreeSizes.clear();
        dfs(root);
        sort(perfectSubtreeSizes.rbegin(), perfectSubtreeSizes.rend());
        if (perfectSubtreeSizes.size() < k) return -1;
        return perfectSubtreeSizes[k - 1];
    }
};