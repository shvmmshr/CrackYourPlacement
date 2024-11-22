class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> freq;
        int maxfreq = 0;

        for (auto& row : matrix) {
            string canonical = "";
            for (int j = 0; j < row.size(); j++) {
                canonical += (row[j] == row[0] ? '0' : '1');
            }
            freq[canonical]++;
            maxfreq = max(maxfreq, freq[canonical]);
        }

        return maxfreq;
    }
};
