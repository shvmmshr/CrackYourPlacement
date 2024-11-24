class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;

        for (auto& row : matrix) {
            for (int num : row) {
                sum += abs(num);
                if (num < 0) {
                    negativeCount++;
                }
                minAbsValue = min(minAbsValue, abs(num));
            }
        }

        if (negativeCount % 2 != 0) {
            sum -= 2 * minAbsValue;
        }

        return sum;
    }
};
