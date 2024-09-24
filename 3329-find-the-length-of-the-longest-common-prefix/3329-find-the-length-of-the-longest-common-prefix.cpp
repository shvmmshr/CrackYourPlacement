class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size()>arr2.size()){
            swap(arr1,arr2);
        }
        unordered_set<int> prefix_set;
        for(auto &n:arr1){
            while(n!=0 && prefix_set.find(n)==prefix_set.end()){
                prefix_set.insert(n);
                n/=10;
            }
        }
        int ans = 0;
        for(auto &n:arr2){
            while(n!=0 && prefix_set.find(n)==prefix_set.end()){
                n/=10;
            } 
            if(n){
                ans = max(ans,n);
            }
        }
        if (ans==0) return 0;
        return to_string(ans).size();
    }
};