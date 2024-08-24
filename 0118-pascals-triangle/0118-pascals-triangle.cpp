class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> a;
        a.push_back(1);
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            res.push_back(a);
            vector<int> b;
            a.insert(a.begin(),0);
            a.insert(a.end(),0);
            int l=0;
            int r=1;
            while(r<a.size()){
                b.push_back(a[l]+a[r]);
                l++;
                r++;
            }
            a=b;
        }
        return res;
    }
};