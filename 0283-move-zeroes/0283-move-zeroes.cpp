class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int j = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (j == -1)
                    j = i;
            } else {
                if (j != -1) {
                    swap(nums[i], nums[j]);
                    j++;
                }
            }
        }
        return nums;
    }
};
