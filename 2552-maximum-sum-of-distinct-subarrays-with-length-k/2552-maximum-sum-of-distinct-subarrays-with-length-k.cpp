class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0;
        long long maxsum = 0;
        
        int n = nums.size();
        if (n < k) return 0;
        
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            sum += nums[i];
        }

        if (freq.size() == k) {
            maxsum = sum;
        }

        for (int i = k; i < n; i++) {
            int left = nums[i - k];
            freq[left]--;
            sum -= left;
            if (freq[left] == 0) {
                freq.erase(left);
            }

            int right = nums[i];
            freq[right]++;
            sum += right;

            if (freq.size() == k) {
                maxsum = max(maxsum, sum);
            }
        }

        return maxsum;
    }
};
