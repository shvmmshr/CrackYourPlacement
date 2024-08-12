class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int total=0;
        int len=nums.size();
        int median;
        sort(nums.begin(),nums.end());
        if(len%2==0){
            median=(nums[len/2]+nums[len/2-1])/2;
        }
        else{
            median=nums[len/2];
        }
        for(int i=0;i<len;i++){
            total+=abs(nums[i]-median);
        }
        return total;
    }
};