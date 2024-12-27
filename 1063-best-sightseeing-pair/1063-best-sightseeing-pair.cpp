class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = values[0];
        int maxi = INT_MIN;

        for (int j = 1; j < values.size(); j++) {
            maxi = max(maxi, best + values[j] - j);
            best = max(best, values[j] + j);
        }

        return maxi;
    }
};
