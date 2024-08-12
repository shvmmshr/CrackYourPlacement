class Solution {
public:
    void backtrack(int open, int close, int n, vector<string>& res, string& str){
        if (str.size()==2*n){
            res.push_back(str);
            return;
        }
        if (open<n){
            str.push_back('(');
            backtrack(open+1, close, n, res, str);
            str.pop_back();
        }
        if (close<open){
            str.push_back(')');
            backtrack(open, close+1, n, res, str);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str="";
        backtrack(0,0,n,res,str);
        return res;
    }
};