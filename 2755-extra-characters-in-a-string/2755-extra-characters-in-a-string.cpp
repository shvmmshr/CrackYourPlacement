class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX); 
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;

            for (const string& word : dictionary) {
                int wordLen = word.size();
                if (i >= wordLen && s.substr(i - wordLen, wordLen) == word) {
                    dp[i] = min(dp[i], dp[i - wordLen]);
                }
            }
        }

        return dp[n];
    }
};