class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1;
        map<int,int> mp2;
        vector<vector<int>> res;
        for(auto i: nums1) mp1[i]++;
        for(auto i: nums2) mp2[i]++;
        vector<int> n2;
        vector<int> n1;
        for(auto i: mp1){
            if(mp2.find(i.first)==mp2.end()){
                n2.push_back(i.first);
            }
        }
        for(auto i: mp2){
            if(mp1.find(i.first)==mp1.end()){
                n1.push_back(i.first);
            }
        }
        res.push_back(n2);
        res.push_back(n1);
        return res;
    }
};