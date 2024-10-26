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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<vector<pair<int,int>>> levels(1e5,vector<pair<int,int>>(2,{0,0}));
        vector<int> lev(1e5+1,0);
        int ht=height(root,0,levels,lev);
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int node=queries[i];
            int level=lev[node];
            if(levels[level][0].second==node)
            {
                ans.push_back(ht-levels[level][0].first+levels[level][1].first-1);
            }
            else
            {
                ans.push_back(ht-1);
            }
        }
        return ans;
        
    }
    int height(TreeNode* root,int level,vector<vector<pair<int,int>>> &levels,vector<int> &lev)
    {
        if(root==NULL)
            return 0;
        lev[root->val]=level;
        int hleft=height(root->left,level+1,levels,lev);
        int hright=height(root->right,level+1,levels,lev);
        int tmp=1+max(hleft,hright);
        if(tmp>levels[level][0].first)
           {
            levels[level][1]=levels[level][0];
            levels[level][0]={tmp,root->val};
           }
        else if(tmp>levels[level][1].first)
            levels[level][1]={tmp,root->val};
        return 1+max(hleft,hright);
    }
};