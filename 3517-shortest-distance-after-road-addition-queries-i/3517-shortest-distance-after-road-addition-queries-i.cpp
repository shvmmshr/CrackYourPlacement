class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>>& graph, int n) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back({i + 1, 1});
        } 
        vector<int> result;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back({v, 1});
            result.push_back(dijkstra(graph, n));
        }
        return result;
    }
};