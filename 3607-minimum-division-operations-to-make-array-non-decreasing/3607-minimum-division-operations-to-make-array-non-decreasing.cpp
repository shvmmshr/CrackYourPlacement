class Solution {
public:
    int gpd(int n) {
        for (int i = n/2; i >= 2; i--) {
            if (n % i == 0) {
                return i;
            }
        }
        return 1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        map<int,int> oldgpt;
        for (int i = n - 2; i >= 0; i--) {
            while (nums[i] > nums[i + 1]) {
                int div = oldgpt.find(nums[i]) == oldgpt.end() ? gpd(nums[i]) : oldgpt[nums[i]];
                if (div == 1) return -1;
                oldgpt[nums[i]] = div;
                nums[i]/=div;
                operations++;
            }
        }
        return operations;
    }
};
