class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> events;
        for (const auto& interval : intervals) {
            events[interval[0]]++;
            events[interval[1] + 1]--;
        }
        int maxGroups = 0, currentGroups = 0;
        for (const auto& event : events) {
            currentGroups += event.second;
            maxGroups = max(maxGroups, currentGroups);
        }  
        return maxGroups;
    }
};
