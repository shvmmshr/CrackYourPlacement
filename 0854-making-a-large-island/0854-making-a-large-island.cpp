int n, m;
int arr[4] = {-1, 0, 1, 0};
bool isval(int r, int c) { return r >= 0 && c >= 0 && r < n && c < m; }
int value(int i, int j) { return (i * m) + j; }
int bfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid,
        vector<int>& par) {
    vis[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    int ans;
    ans = 1;
    int val = value(r, c);
    par[val] = val;
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int rr = it.first;
        int cc = it.second;
        for (int i = 0; i < 4; i++) {
            int nr = arr[i] + rr;
            int nc = arr[3 - i] + cc;
            if (isval(nr, nc) && grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                ans++;
                vis[nr][nc] = 1;
                q.push({nr, nc});
                par[value(nr, nc)] = val;
            }
        }
    }
    return ans;
}
int func(vector<vector<int>>& grid, vector<int>& par,
         unordered_map<int, int>& mpp) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {
                int val = value(i, j);
                mpp[val] = bfs(i, j, vis, grid, par);
                ans = max(ans, mpp[val]);
            }
        }
    }
    return ans;
}

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> par(m * n);
        unordered_map<int, int> mpp;
        int ans = func(grid, par, mpp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    int val = value(i, j);
                    unordered_map<int, int> mpp2;
                    for (int k = 0; k < 4; k++) {
                        int nr = arr[k] + i;
                        int nc = arr[3 - k] + j;

                        if (isval(nr, nc) && grid[nr][nc] == 1) {
                            mpp2[par[value(nr, nc)]] = mpp[par[value(nr, nc)]];
                        }
                    }
                    int an = 0;
                    for (auto it : mpp2)
                        an += it.second;
                    an++;
                    ans = max(ans, an);
                }
            }
        }
        return ans;
    }
};