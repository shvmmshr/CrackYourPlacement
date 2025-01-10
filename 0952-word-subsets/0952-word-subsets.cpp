class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26, 0);
        for (string& word : words2) {
            vector<int> temp(26, 0);
            for (char c : word) {
                temp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                count[i] = max(count[i], temp[i]);
            }
        }
        vector<string> res;
        for (string& word : words1) {
            vector<int> temp(26, 0);
            for (char c : word) {
                temp[c - 'a']++;
            }
            bool result = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] < count[i]) {
                    result = false;
                    break;
                }
            }
            if (result) {
                res.push_back(word);
            }
        }
        return res;
    }
};