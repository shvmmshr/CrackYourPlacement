/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==NULL){
            return {};
        }
        vector<int> res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            for(auto child: temp->children){
                s.push(child);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};