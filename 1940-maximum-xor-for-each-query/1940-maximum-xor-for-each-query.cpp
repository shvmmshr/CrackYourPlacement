class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxK = (1 << maximumBit) - 1;
        int totalXor = 0;
        for (int num : nums) {
            totalXor ^= num;
        }       
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = totalXor ^ maxK;
            totalXor ^= nums[n - 1 - i];
        }
        return ans;
    }
};