class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, 
        pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        int result = 0;
        int maxHeight = INT_MIN;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int height = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;
            
            maxHeight = max(maxHeight, height);
            
            for (auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (heightMap[nx][ny] < maxHeight) {
                        result += maxHeight - heightMap[nx][ny];
                    }
                    visited[nx][ny] = true;
                    pq.push({heightMap[nx][ny], {nx, ny}});
                }
            }
        }
        
        return result;
    }
};