class Solution {
public:
    int ans(vector<int>& nums, int& t, int curr, int i) {
        if (i >= nums.size())
            return curr == t;
        return ans(nums, t, curr + nums[i], i + 1) +
               ans(nums, t, curr - nums[i], i + 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return ans(nums, target, 0, 0);
    }
};