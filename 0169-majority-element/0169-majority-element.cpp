class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        int a=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==a)  res++;
            else if(nums[i]!=a && res>0) res--;
            else a=nums[i];
        }
        return a;
    }
};