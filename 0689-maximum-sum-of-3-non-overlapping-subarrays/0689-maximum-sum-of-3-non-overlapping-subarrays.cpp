class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1, 0);
        sum[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        for(int i = 1; i < sum.size(); ++i){
            sum[i] = sum[i-1] - nums[i-1] + nums[i + k - 1];
        }

        vector<int> left(sum.size(), 0);
        int best = 0;
        for(int i = 0; i < sum.size(); ++i){
            if(sum[i] > sum[best]){
                best = i;
            }
            left[i] = best;
        }

        vector<int> right(sum.size(), sum.size() - 1);
        best = sum.size() - 1;
        for(int i = sum.size() - 1; i >= 0; --i){
            if(sum[i] >= sum[best]){
                best = i;
            }
            right[i] = best;
        }

        vector<int> result(3, 0);
        int max_sum = 0;
        for(int i = k; i < sum.size() - k; ++i){
            int total = sum[left[i - k]] + sum[i] + sum[right[i + k]];
            if(total > max_sum){
                max_sum = total;
                result = {left[i - k], i, right[i + k]};
            }
        }
        return result;
    }
};