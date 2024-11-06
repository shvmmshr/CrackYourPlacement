class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> values = nums;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (values[j] <= values[j + 1]) {
                    continue;
                } else {
                    int countJ = bitset<32>(values[j]).count();
                    int countJ1 = bitset<32>(values[j + 1]).count();
                    if (countJ == countJ1) {
                        swap(values[j], values[j + 1]);
                    } else {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
