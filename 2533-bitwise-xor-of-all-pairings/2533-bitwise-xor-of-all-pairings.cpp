class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        long m=nums1.size();
        long n=nums2.size();
        int ans=0;
        unordered_map<int ,int> mpp;
        for(int i:nums1) mpp[i]+=n;
        for(int i:nums2) mpp[i]+=m;
        for(auto x :mpp) {
            if(x.second&1) ans^=x.first;
            else ans^=0;
        }
        return ans;
    }
};