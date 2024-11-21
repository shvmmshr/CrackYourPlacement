class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (int i = 0; i < candies.size(); i++) {
            res.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return res;
    }
};