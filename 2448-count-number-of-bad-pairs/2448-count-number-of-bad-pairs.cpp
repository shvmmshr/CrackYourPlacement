class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long)n * (n - 1) / 2;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[i - nums[i]]++;
        }
        long long good = 0;
        for (auto it: freq) {
            int count = it.second;
            good += ((long long)count * (count - 1) / 2);
        }

        return total - good;
    }
};
