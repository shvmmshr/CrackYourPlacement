class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int maxVal, minVal;
        long long l = 0, r = 0;
        map<int,int> freq;
        while (r < n) {
            freq[nums[r]]++;
            maxVal = freq.rbegin()->first;
            minVal = freq.begin()->first;
            int diff = maxVal-minVal;
            while (diff > 2) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) freq.erase(nums[l]);
                maxVal = freq.rbegin()->first;
                minVal = freq.begin()->first;
                diff = maxVal-minVal;
                l++;
            }
            r++;
            count += (r-l);
        }
        return count;
    }
};