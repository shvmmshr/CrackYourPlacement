class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto x:arr){
            mp[(x%k+k)%k]++;
        }
        for(auto x:arr){
            if(x%k==0){
                if(mp[x%k]%2!=0){
                    return false;
                }
            }
            else if(mp[x%k]!=mp[k-x%k]){
                return false;
            }
        }
        return true; 
    }
};