class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int count = 0;
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                node->count++;
            }
        }
        
        vector<int> res;
        for (const string& word : words) {
            TrieNode* node = root;
            int sum = 0;
            for (char c : word) {
                node = node->children[c];
                sum += node->count;
            }
            res.push_back(sum);
        }
        
        return res;
    }
};
