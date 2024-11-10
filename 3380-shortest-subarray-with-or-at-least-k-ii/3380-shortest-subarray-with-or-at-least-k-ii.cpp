class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = INT_MAX;
        unordered_map<int, int> prev;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> curr;
            curr[nums[i]] = 1;

            for (const auto& [orValue, length] : prev) {
                int newOr = orValue | nums[i];
                int newLength = length + 1;

                if (!curr.count(newOr) || curr[newOr] > newLength) {
                    curr[newOr] = newLength;
                }
            }

            for (const auto& [orValue, length] : curr) {
                if (orValue >= k) {
                    minLength = min(minLength, length);
                }
            }

            prev = move(curr);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};