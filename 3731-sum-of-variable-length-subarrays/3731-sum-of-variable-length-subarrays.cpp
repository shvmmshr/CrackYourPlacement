class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int sm = 0;
        int start = 0;
        for(int i=0; i<n; i++){
            start = max(0,i-nums[i]);
            for(int j=start; j<=i; j++){
                sm += nums[j];
            }
        }
        return sm;
    }
};