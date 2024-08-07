class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int curSum=0;
        vector<int> prefixSums;
        for(int i=0;i<nums.size();i++){
            curSum+=nums[i];
            int diff=curSum-k;
            if(diff==0) res++;
            for(int j=0;j<prefixSums.size();j++){
                if(prefixSums[j]==diff) res++;
            }
            prefixSums.push_back(curSum);
        }
        return res;
    }
};