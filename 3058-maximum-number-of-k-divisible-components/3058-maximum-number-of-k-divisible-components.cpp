class Solution {
public:
    int ans = 0;
    long dfs(int node, vector<int>& values, int k, vector<bool>& visited, vector<vector<int>>& adj) {
        long carry = 0;
        if(visited[node]) return 0;
        visited[node] = true;
        for(int next: adj[node]) {
            if(next == node) continue;
            carry += dfs(next, values, k, visited, adj);
        }
        carry += values[node];
        if((carry)%k == 0) {
            ans++;
            carry = 0;
        }
        return carry;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        dfs(0, values, k, visited, adj);
        return ans;
    }
};