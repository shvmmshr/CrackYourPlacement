class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()-1){
                if(nums[i]>nums[i+1]) 
                    return nums[i+1];
            }
        }
        return nums[0];
    }
};