class Solution {
public:
    vector<vector<int>> adj1, adj2;

    pair<int, int> bfs(const vector<vector<int>>& adj, int start) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthest = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neigh : adj[node]) {
                if (dist[neigh] == -1) {
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                    if (dist[neigh] > dist[farthest]) {
                        farthest = neigh;
                    }
                }
            }
        }
        return {farthest, dist[farthest]};
    }

    int shivam(const vector<vector<int>>& adj) {
        auto [s, d1] = bfs(adj, 0); 
        auto [e, d2] = bfs(adj, s);
        return d2;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        adj1.resize(n);
        adj2.resize(m);
        for ( auto e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for ( auto e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        int d1 = shivam(adj1);
        int d2 = shivam(adj2);

        
        return max(d1, max(d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1));
    }
};