class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int res = 0;
        long long totalSum = 0, leftSum = 0;
        for (int num : nums) {
            totalSum += num;
        } 
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            if (leftSum >= totalSum - leftSum) {
                res++;
            }
        }   
        return res;
    }
};
