class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return helper(s, 0, seen);
    }
    
    int helper(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0;
        }
        int maxCount = 0;
        string temp = "";
        for (int i = start; i < s.size(); i++) {
            temp += s[i];
            if (seen.find(temp) == seen.end()) {
                seen.insert(temp);
                maxCount = max(maxCount, 1 + helper(s, i + 1, seen));
                seen.erase(temp);
            }
        }
        return maxCount;
    }
};
