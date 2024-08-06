class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> arr;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(j<k){
                if(k<nums.size()-1 && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }
                if(nums[i]+nums[j]+nums[k]==0){
                    arr.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return arr;
    }
};