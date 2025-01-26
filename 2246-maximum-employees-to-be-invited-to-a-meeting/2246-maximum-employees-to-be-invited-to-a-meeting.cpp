class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size(), maxCycle = 0, pairChains = 0;
        queue<int> q;
        vector<bool> visited(n);
        vector<int> inDeg(n), chainLen(n); 
        for (int x : fav) inDeg[x]++;
        for (int i = 0; i < n; ++i) 
            if (!inDeg[i]) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited[u] = true;
            int nbr = fav[u];
            chainLen[nbr] = max(chainLen[nbr], chainLen[u] + 1);
            if (--inDeg[nbr] == 0) q.push(nbr);
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int cycleLen = 0, u = i;
            while (!visited[u]) {
                visited[u] = true;
                u = fav[u];
                cycleLen++;
            }
            if (cycleLen == 2) 
                pairChains += 2 + chainLen[i] + chainLen[fav[i]];
            else 
                maxCycle = max(maxCycle, cycleLen);
        }
        return max(maxCycle, pairChains);
    }
};