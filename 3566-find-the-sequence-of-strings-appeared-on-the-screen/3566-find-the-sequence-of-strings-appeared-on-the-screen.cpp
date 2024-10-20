class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string current = "";
        for (char c : target) {
            if (current.empty()) {
                current = "a";
            } else {
                current += "a";
            }
            result.push_back(current);
            while (current.back() != c) {
                current.back() = (current.back() - 'a' + 1) % 26 + 'a';
                result.push_back(current);
            }
        }
        return result;
    }
};
