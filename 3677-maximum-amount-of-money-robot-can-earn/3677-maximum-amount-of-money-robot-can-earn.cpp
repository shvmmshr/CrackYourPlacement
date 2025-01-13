class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = (int)coins.size(), m = (int)coins[0].size();
        long dp[3][n][m]; 
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    dp[k][i][j] = -1e9;
                }
            }
        }

        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[1][0][0] = 0;
            dp[2][0][0] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 2; k >= 0; k--) {
                    if (i == 0 && j == 0) continue;

                    if (i > 0) {
                        dp[k][i][j] = max(dp[k][i][j], dp[k][i - 1][j] + coins[i][j]);
                        if (coins[i][j] < 0 && k > 0) {
                            dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j]);
                        }
                    }
                    if (j > 0) {
                        dp[k][i][j] = max(dp[k][i][j], dp[k][i][j - 1] + coins[i][j]);
                        if (coins[i][j] < 0 && k > 0) {
                            dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j - 1]);
                        }
                    }
                }
            }
        }

        return max({dp[0][n - 1][m - 1], dp[1][n - 1][m - 1], dp[2][n - 1][m - 1]});
    }
};