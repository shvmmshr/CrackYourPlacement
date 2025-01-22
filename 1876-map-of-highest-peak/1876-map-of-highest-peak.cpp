class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j < n ;j++){
            if(isWater[i][j] == 1){
                ans[i][j] = 0;
                q.push({{i,j},0});
                visited[i][j] = true;
            }
            }
        }
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        while(!q.empty()){
            int frontI = q.front().first.first;
            int frontJ = q.front().first.second;
            int value = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int newX = frontI + dx[i];
                int newY = frontJ + dy[i];
                if(newX >= 0 && newY >= 0 && newX < m && newY < n && visited[newX][newY] == false){
                    visited[newX][newY] = true;
                    ans[newX][newY] = value + 1;
                    q.push({{newX,newY},value+1});
                }
            }
        }
        return ans;
    }
};