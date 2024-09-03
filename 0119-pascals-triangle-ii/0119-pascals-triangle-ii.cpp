class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res={1};
        for(int i=0;i<rowIndex;i++){
            vector<int> nxtrow(res.size() + 1, 0);
            for(int j=0;j<res.size();j++){
                nxtrow[j]+=res[j];
                nxtrow[j+1]+=res[j];
            }
            res=nxtrow;
        }
        return res;

    }
};