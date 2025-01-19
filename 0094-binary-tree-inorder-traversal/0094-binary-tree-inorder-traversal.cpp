class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        in(root, v);
        return v;
    }
    void in(TreeNode* root, vector<int> &v){
        if(root == NULL)return;
        in(root->left, v);
        v.push_back(root->val);
        in(root->right,v);
    }
};