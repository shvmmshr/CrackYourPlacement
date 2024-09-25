class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        int count = 0;
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
                node->count++;
            }
        }
        
        vector<int> res;
        for (const string& word : words) {
            TrieNode* node = root;
            int sum = 0;
            for (char c : word) {
                node = node->children[c - 'a'];
                sum += node->count;
            }
            res.push_back(sum);
        }
        
        return res;
    }
};
