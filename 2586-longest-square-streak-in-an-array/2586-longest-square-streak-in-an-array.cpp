class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        set<int> s(nums.begin(), nums.end());
        for(int num:nums){
            int count=1;
            long long cur=num;
            while (cur <= INT_MAX / cur && s.find(cur * cur) != s.end()) {
                cur = cur * cur;
                count++;
            }
            maxi=max(maxi,count);
        }
        return maxi > 1 ? maxi : -1;
    }
};
