class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur=nums[0];
        int maxi=cur;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                cur+=nums[i];
            }
            else cur=nums[i];
            maxi=max(cur,maxi);
        }
        return maxi;
    }
};