class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            auto start = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto end = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            count += distance(start, end);
        }  
        return count;
    }
};