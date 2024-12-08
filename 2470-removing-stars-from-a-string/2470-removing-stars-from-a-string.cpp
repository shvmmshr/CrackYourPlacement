class Solution {
public:
    string removeStars(string s) {
        stack<char> ss;
        for(char c:s){
            if(c=='*'){
                if(!ss.empty()) ss.pop();
            }
            else ss.push(c);
        }
        s="";
        while(!ss.empty()){
            s+=ss.top();
            ss.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};