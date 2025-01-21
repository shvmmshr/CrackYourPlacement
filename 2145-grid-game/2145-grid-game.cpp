class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> topSum(n + 1, 0), bottomSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            topSum[i] = topSum[i - 1] + grid[0][i - 1];
            bottomSum[i] = bottomSum[i - 1] + grid[1][i - 1];
        }
        long long result = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            long long topRemaining = topSum[n] - topSum[i];
            long long bottomRemaining = bottomSum[i - 1];
            result = min(result, max(topRemaining, bottomRemaining));
        }
        return result;
    }
};