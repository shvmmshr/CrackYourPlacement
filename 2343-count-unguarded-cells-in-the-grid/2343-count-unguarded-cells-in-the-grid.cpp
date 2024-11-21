class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int res = 0;

        for (auto& it : guards) {
            grid[it[0]][it[1]] = 1;
        }
        for (auto& it : walls) {
            grid[it[0]][it[1]] = 2;
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& it : guards) {
            for (auto& dir : directions) {
                int x = it[0], y = it[1];
                while (true) {
                    x += dir.first;
                    y += dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2 || grid[x][y] == 1) break;
                    if (grid[x][y] == 0) grid[x][y] = 3;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) res++;
            }
        }

        return res;
    }
};
