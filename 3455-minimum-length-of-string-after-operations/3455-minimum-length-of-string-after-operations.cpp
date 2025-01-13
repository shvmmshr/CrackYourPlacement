class Solution {
public:
    int minimumLength(string s) {
        int res=0;
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it: mp){
            it.second=it.second%2;
            res+=(it.second==0)?2:1;
        }
        return res;
    }
};