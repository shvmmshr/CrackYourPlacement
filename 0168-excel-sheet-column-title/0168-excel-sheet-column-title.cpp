class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while (columnNumber>=1){
            res.push_back((columnNumber-1)%26+'A');
            columnNumber=(columnNumber-1)/26;
        }

        reverse(res.begin(),res.end());
        return res;
    }
};