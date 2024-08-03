class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len= nums.size();
        if(len==0){
            return 0;
        }
        if(len==1){
            return 1;
        }
        int i=0;
        int j=1;
        for(j=1;j<len;j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};