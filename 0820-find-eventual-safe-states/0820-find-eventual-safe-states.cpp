class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, unordered_map<int, bool>& mpp) {
        if (mpp.find(i) != mpp.end()) return mpp[i];
        mpp[i] = false;
        for (auto it : graph[i]) {
            if (!dfs(it, graph, mpp)) return false;
        }
        mpp[i] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, bool> mpp;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, mpp)) res.push_back(i);
        }
        return res;
    }
};