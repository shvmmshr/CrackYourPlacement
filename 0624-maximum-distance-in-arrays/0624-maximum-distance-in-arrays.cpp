class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min1=arrays[0][0],max1=arrays[0].back();
        int res=0;
        for(int i=1;i<arrays.size();i++){
            res=max(res,max(abs(arrays[i].back()-min1),abs(max1-arrays[i][0])));
            min1=min(min1,arrays[i][0]);
            max1=max(max1,arrays[i].back());
        }
        return res;
    }
};