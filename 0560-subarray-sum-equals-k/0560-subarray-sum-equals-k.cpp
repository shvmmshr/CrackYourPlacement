class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int curSum=0;
        map <int, int> mp;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            curSum+=nums[i];
            if(mp.find(curSum-k)!=mp.end()){
                res+=mp[curSum-k];
            }
            mp[curSum]++;
        }
        return res;
    }
};