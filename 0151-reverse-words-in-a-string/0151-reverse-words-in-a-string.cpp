class Solution {
public:
    string reverseWords(string s) {
        string res="";
        stringstream ss(s);
        vector<string> str;
        string word;
        while(ss>>word) str.push_back(word);
        for(int i=str.size()-1;i>=0;i--){
            res+=str[i];
            if(i!=0) res+=" ";
        }
        return res;
    }
};