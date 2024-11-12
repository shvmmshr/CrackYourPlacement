class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> queriesWithIndex;
        for (int i = 0; i < queries.size(); i++) {
            queriesWithIndex.push_back({queries[i], i});
        }
        sort(queriesWithIndex.begin(), queriesWithIndex.end());
        vector<int> res(queries.size());
        int i = 0;
        int maxBeauty = 0;
        for (auto& [q, idx] : queriesWithIndex) {
            while (i < items.size() && items[i][0] <= q) {
                maxBeauty = max(maxBeauty, items[i][1]);
                i++;
            }
            res[idx] = maxBeauty;
        }
        return res;
    }
};