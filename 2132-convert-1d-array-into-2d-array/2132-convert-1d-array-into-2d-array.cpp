class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (m * n != original.size()) return res;
        res.resize(m, vector<int>(n));
        for (int i = 0; i < m * n; i++) {
            res[i / n][i % n] = original[i];
        }
        return res;
    }
};