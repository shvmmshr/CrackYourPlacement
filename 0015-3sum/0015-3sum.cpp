class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;  
                    while (j < k && nums[k] == nums[k - 1]) k--;  
                    
                    j++;  // Move left pointer to the right
                    k--;  // Move right pointer to the left
                } else if (sum > 0) {
                    k--;  // Sum too large, decrease `k`
                } else {
                    j++;  // Sum too small, increase `j`
                }
            }
        }

        return ans;  // Return all unique triplets
    }
};