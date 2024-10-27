class Solution {
public:
    int hello(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& visited, int rows, int cols) {
        if (r == rows || c == cols || matrix[r][c] == 0) return 0;
        if (visited[r][c] != -1) return visited[r][c];

        int length = 1 + min({hello(r + 1, c, matrix, visited, rows, cols), 
                              hello(r, c + 1, matrix, visited, rows, cols), 
                              hello(r + 1, c + 1, matrix, visited, rows, cols)});
        visited[r][c] = length;
        return length;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int res = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res += hello(i, j, matrix, visited, rows, cols);
            }
        }
        return res;
    }
};
