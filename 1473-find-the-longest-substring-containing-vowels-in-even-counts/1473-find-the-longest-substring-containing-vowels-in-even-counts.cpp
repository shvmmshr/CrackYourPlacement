class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> dp(1 << 5, -1);
        dp[0] = 0;
        int mask = 0, ans = 0;
        unordered_map<char, int> vowels = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        
        for (int i = 0; i < n; ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                mask ^= 1 << vowels[s[i]];
            }
            
            if (dp[mask] == -1) {
                dp[mask] = i + 1;
            }
            
            ans = max(ans, i - dp[mask] + 1);
        }
        
        return ans;
        
    }
};