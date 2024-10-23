class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        
        root->val = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            
            vector<TreeNode*> nodes;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);
                
                if (node->left) {
                    levelSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    levelSum += node->right->val;
                    q.push(node->right);
                }
            }
            
            for (TreeNode* node : nodes) {
                int siblingSum = 0;
                
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;
                
                if (node->left) node->left->val = levelSum - siblingSum;
                if (node->right) node->right->val = levelSum - siblingSum;
            }
        }
        
        return root;
    }
};
