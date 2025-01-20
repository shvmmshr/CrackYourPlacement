class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        unordered_map<int, pair<int, int>> ump;
        vector<int> row_cnt(rows);
        vector<int> col_cnt(cols);
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                int val = mat[r][c];
                ump[val] = {r, c};
            }
        }
        for(int i=0; i<arr.size(); i++){
            int num = arr[i];
            auto [r, c] = ump[num];
            row_cnt[r]++;
            col_cnt[c]++;
            if(row_cnt[r] == cols || col_cnt[c] == rows){
                return i;
            }
        }
        return -1;
    }
};