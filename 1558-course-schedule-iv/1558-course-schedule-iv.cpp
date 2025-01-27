class Solution {
public:
    void dfs(int node, set<int>& visited, vector<vector<int>>& adjacent, vector<int>& vis) {
        vis[node] = 1;
        visited.insert(node);
        for (auto i : adjacent[node]) {
            if (vis[i] == 0) {
                dfs(i, visited, adjacent, vis);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        if (prerequisites.size() == 0) {
            vector<bool> result;
            for (auto query : queries) {
                result.push_back(false);
            }
            return result;
        }
        vector<vector<int>> adjacent(numCourses);
        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adjacent[a].push_back(b);
        }
        vector<set<int>> reachability(numCourses);
        for (int i = 0; i < numCourses; i++) {
            set<int> visited;
            vector<int> vis(numCourses, 0);
            dfs(i, visited, adjacent, vis);
            reachability[i] = visited;
        }

        vector<bool> ans;
        for (auto it : queries) {
            int a = it[0];
            int b = it[1];
            if (reachability[a].find(b) != reachability[a].end()) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};