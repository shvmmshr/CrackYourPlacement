class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int count0 = 0;
        int res = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                count0++;
            }
            while (count0 > k) {
                if (nums[l] == 0) {
                    count0--;
                }
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
