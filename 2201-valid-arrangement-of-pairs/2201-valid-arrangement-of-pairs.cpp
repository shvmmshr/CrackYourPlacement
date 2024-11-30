class Solution {
public:
    void dfs(int node, vector<vector<int>>& ans,
             unordered_map<int, vector<int>> &adj) {

                while(adj[node].size()!=0){
                    int next=adj[node].back();
                    adj[node].pop_back();
                    dfs(next,ans,adj);
                    ans.push_back({node,next});
                }
             }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        map<int, int> in, out;

        int n = pairs.size();
        int m = pairs[0].size();

        for (auto it : pairs) {
            adj[it[0]].push_back(it[1]);
            out[it[0]]++;
            in[it[1]]++;
        }
        int start = -1;
        for (auto it : adj) {
            if (out[it.first] - in[it.first] == 1) {
                start = it.first;
                break;
            }
        }
        if(start==-1)
        start=pairs[0][0];

        vector<vector<int>> ans;
        dfs(start, ans, adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};