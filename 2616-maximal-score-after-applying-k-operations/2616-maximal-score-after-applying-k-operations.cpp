class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while (k > 0 && !pq.empty()) {
            auto [topValue, index] = pq.top();
            pq.pop();
            score += topValue;
            nums[index] = ceil(topValue / 3.0);
            pq.push({nums[index], index});
            k--;
        }
        return score;
    }
};
