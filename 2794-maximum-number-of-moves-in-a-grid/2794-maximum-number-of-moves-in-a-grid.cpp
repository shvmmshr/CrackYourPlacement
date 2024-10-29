class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size();
        if (dp[row][col] != -1) return dp[row][col];
        int moves = 0;
        if (row > 0 && col + 1 < n && grid[row - 1][col + 1] > grid[row][col]) {
            moves = max(moves, 1 + dfs(row - 1, col + 1, grid, dp));
        }
        if (col + 1 < n && grid[row][col + 1] > grid[row][col]) {
            moves = max(moves, 1 + dfs(row, col + 1, grid, dp));
        }
        if (row + 1 < m && col + 1 < n && grid[row + 1][col + 1] > grid[row][col]) {
            moves = max(moves, 1 + dfs(row + 1, col + 1, grid, dp));
        }
        return dp[row][col] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int max_moves = 0;

        for (int i = 0; i < m; i++) {
            max_moves = max(max_moves, dfs(i, 0, grid, dp));
        }

        return max_moves;
    }
};