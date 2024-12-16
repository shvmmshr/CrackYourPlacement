class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        while(k--){
            int mini=INT_MAX;
            int idx=-1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<mini){
                    mini=nums[i];
                    idx=i;
                }
            }
            nums[idx]=nums[idx]*m;
        }
        return nums;
    }
};