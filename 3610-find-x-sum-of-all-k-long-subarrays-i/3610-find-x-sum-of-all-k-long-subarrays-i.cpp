class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        
        for (int i = 0; i <= n - k; i++) {
            map<int, int> freqMap; 
            long long sum = 0;
            int count = 0;
            for (int j = i; j < i + k; j++) {
                freqMap[nums[j]]++;
            }
            vector<pair<int, int>> sortedFreqMap(freqMap.begin(), freqMap.end());
            sort(sortedFreqMap.begin(), sortedFreqMap.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second == b.second ? a.first > b.first : a.second > b.second;
            });
            for (const auto& it : sortedFreqMap) {
                sum += it.first * it.second;
                count++;
                if (count == x) {
                    break;
                }
            }
            result.push_back(sum);
        }
        return result;
    }
};
