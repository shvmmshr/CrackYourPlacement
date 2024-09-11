class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            sum=(sum<0)?0:sum;
        }
        return maxi;
    }
};