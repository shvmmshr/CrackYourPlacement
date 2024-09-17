class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> res;
        istringstream iss(s1 + " " + s2);
        string word;
        while (iss >> word) {
            mp[word]++;
        }
        for (auto &p : mp) {
            if (p.second == 1) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};