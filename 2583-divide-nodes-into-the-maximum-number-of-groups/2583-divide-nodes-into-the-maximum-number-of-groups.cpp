class Solution {
public:
    void bfs(int v, vector<vector<int>>& adj, vector<int>& component, int& comp) {
        queue<int>q;
        q.push(v);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            component[cur] = comp;
            for (int neighbor : adj[cur])
                if (!component[neighbor])
                    component[neighbor] = comp, q.push(neighbor);
        }
    }
    
    int bfs2(int vertex, vector<vector<int>>& adj, int n) {
        vector<int>color(n + 1, 0);
        color[vertex] = 1;
        queue<int>q;
        q.push(vertex);
        while (!q.empty()){
            int v = q.front();
            q.pop();
            for (int neighbor : adj[v]){
                if (color[neighbor] == 0){
                    color[neighbor] = color[v] + 1;
                    q.push(neighbor);
                }
                else if (abs(color[neighbor] - color[v]) != 1)
                    return -1;
            }
        }
        return *max_element(color.begin(), color.end());
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n + 1);
        for (vector<int>&edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>component(n + 1, 0);
        int comp = 1;

        for (int i = 1; i <= n; i++)
            if (!component[i])
                bfs(i, adj, component, comp), comp++;
        
        vector<vector<int>>members(comp);
        for (int i = 1; i <= n; i++)
            members[component[i]].push_back(i);

        int ans = 0;
        for (vector<int>&m : members){
            if (m.empty())
                continue;
            int best = -1;
            for (int start : m)
                best = max(best, bfs2(start, adj, n));
            if (best == -1)
                return -1;
            ans += best;
        }
        return ans;
    }
};
