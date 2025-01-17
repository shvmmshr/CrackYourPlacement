class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for(int i = 0; i < derived.size(); i++){
            x ^= derived[i];
        }
        return (x == 0);
    }
};