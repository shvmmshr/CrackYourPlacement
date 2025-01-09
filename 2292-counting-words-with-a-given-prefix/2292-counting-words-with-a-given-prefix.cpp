class Solution {
public:
    int prefixCount(vector<string>& arr, string pref) {
        int ans = 0;
        int n = pref.size();
        for(auto &it:arr){
            if(it.size()>=n&&pref == it.substr(0,n)){
                ans++;
            }
        }
        return ans;
    }
};