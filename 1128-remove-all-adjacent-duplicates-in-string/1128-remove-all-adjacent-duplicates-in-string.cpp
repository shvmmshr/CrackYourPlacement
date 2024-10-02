class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> n;
        string res="";
        for(int i=0;i<s.size();i++){
            if(n.empty()==true){
                n.push(s[i]);
            }
            else if(n.top()==s[i]){
                n.pop();
            }
            else{
                n.push(s[i]);
            }
        }
        while(n.empty()==false){
            res+=n.top();
            n.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};