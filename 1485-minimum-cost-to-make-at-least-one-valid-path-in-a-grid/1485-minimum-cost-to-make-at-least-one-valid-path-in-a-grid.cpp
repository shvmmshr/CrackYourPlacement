class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
        vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        q.push({0, {0, 0}});
        dist[0][0]=0;
        int ans=INT_MAX, ni, nj, a, b, c;
        int ar[4] = {0, 0, 1, -1};
        int br[4] = {1, -1, 0, 0};

        while(!q.empty()){
            a=q.top().first, b=q.top().second.first, c=q.top().second.second;
            if(b==grid.size()-1 && c==grid[0].size()-1) return a;
            q.pop();            
            if(a>dist[b][c]) continue;
            for(int i=0;i<4;i++){
                ni=b+ar[i], nj=c+br[i];
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size()){
                    if(i==grid[b][c]-1 && dist[ni][nj]>a) dist[ni][nj]=a, q.push({a, {ni, nj}});
                    else if(i!=grid[b][c]-1 && dist[ni][nj]>a+1) dist[ni][nj]=a+1, q.push({a+1, {ni, nj}});
                }                
            }            
        }
        return ans;
    }
};