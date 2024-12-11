class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int i=0,j=0;
        while(i<nums.size()){
            while(j<nums.size()-1 && nums[j+1]-nums[i]<=2*k) j++;
            ans=max(ans,j-i+1);
            i++;
        }
        return ans;
    }
};