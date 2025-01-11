class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        unordered_map<char, int> cc;
        for (char c : s) {
            cc[c]++;
        }
        int odd = 0;
        for (auto& it : cc) {
            if (it.second % 2 != 0) odd++;
        }
        return odd <= k;
    }
};