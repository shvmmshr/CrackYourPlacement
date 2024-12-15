class Solution {
public:
    void iterate(TreeNode* root, vector<int>& arr){
	    vector<TreeNode*> s;
	    s.push_back(root);
	    while (!s.empty()){
		    TreeNode* node = s.back(); 
            s.pop_back();
		    if (!node->left && !node->right) 
                arr.push_back(node->val);	
		    if (node->right) s.push_back(node->right);
		    if (node->left)  s.push_back(node->left);
		}
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        iterate(root1, arr1);
        iterate(root2, arr2);
        return arr1==arr2;
    }
};