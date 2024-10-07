class Solution {
public:
    int minLength(string s) {
        stack<char> n;
        for(char c:s){
            if(n.empty()) n.push(c);
            else if(c=='B' && n.top()=='A') n.pop();
            else if(c=='D' && n.top()=='C') n.pop();
            else n.push(c);
        }
        return n.size();
    }
};