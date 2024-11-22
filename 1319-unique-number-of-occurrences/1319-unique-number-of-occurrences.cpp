class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;
        for(auto i: arr){
            freq[i]++;
        }
        for(auto i: freq){
            for(auto j: freq){
                if(i.first != j.first && i.second == j.second){
                    return false;
                }
            }
        }
        return true;
    }
};