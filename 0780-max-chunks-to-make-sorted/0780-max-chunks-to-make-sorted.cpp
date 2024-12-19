class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curmax=-1, ans=0;
        for (int i=0; i<arr.size(); i++) {
            curmax=max(curmax, arr[i]);
            if (curmax==i) ans++;
        }
        return ans;
    }
};