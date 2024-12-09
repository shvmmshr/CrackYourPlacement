class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int maxi=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target){
                maxi=min(maxi,i);
            }
        }
        return maxi==INT_MAX?nums.size():maxi;
    }
};