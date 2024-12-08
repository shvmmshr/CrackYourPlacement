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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(root!=NULL)
        q.push({root, 0});
        int i = 0;
        while (!q.empty()) {
            int x = (q.front()).second;
            i = max(i, x + 1);
            TreeNode* temp = q.front().first;

            if ((temp->left)!= NULL) {
                q.push({temp->left, x + 1});
            }
            if ((temp->right) != NULL) {
                q.push({temp->right, x + 1});
            }
            q.pop();
        }
        return i;
    }
};