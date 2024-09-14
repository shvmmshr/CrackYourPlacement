class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxAnd = nums[0];
        for (int i = 1; i < n; i++) {
            maxAnd = max(maxAnd, nums[i]);
        }
        int longest = 0, currentLength = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxAnd) {
                currentLength++;
                longest = max(longest, currentLength);
            } else {
                currentLength = 0;
            }
        }
        return longest;
    }
};
