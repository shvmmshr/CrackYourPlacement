class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);
        for(int i = 0; i<n; i++){
            vec[i].first = nums[i];
            vec[i].second = i;
        }
        int low = 0;
        sort(vec.begin(), vec.end());
        vector<int> sorted(n);
        sorted [0] = vec[0].second;
        for(int i = 1; i<n; i++){
            if(abs(vec[i].first-vec[i-1].first)>limit){
                sort(sorted.begin() + low, sorted.begin() + i);
                low = i;
            }
            sorted [i] = vec[i].second;
        }
        sort(sorted.begin() + low, sorted.end());
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            ans[sorted[i]] = vec[i].first;
        }
        return ans;
    }
};