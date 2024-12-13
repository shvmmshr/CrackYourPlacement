
class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> numWithIndex;
        long long sum = 0;
        vector<int> marked;

        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.emplace_back(nums[i], i);
        }
        
        sort(numWithIndex.begin(), numWithIndex.end());
        
        for (const auto& pair : numWithIndex) {
            int num = pair.first;
            int idx = pair.second;
            if (find(marked.begin(), marked.end(), idx) == marked.end()) {
                sum += num;
                marked.push_back(idx);
                if (idx > 0) marked.push_back(idx - 1);
                if (idx < nums.size() - 1) marked.push_back(idx + 1);
            }
        }

        return sum;
    }
};
