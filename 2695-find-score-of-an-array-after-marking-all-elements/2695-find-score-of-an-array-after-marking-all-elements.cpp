class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> numWithIndex;
        numWithIndex.reserve(nums.size());
        long long sum = 0;
        vector<bool> marked(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.emplace_back(nums[i], i);
        }
        sort(numWithIndex.begin(), numWithIndex.end());
        for (auto& pair : numWithIndex) {
            int num = pair.first;
            int idx = pair.second;
            if (!marked[idx]) {
                sum += num;
                marked[idx] = true;
                if (idx > 0) marked[idx - 1] = true;
                if (idx < nums.size() - 1) marked[idx + 1] = true;
            }
        }

        return sum;
    }
};