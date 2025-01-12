class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2==1){
            return false;
        }
        int a = 0;
        int b = 0;
        for(int i = 0; i<s.length(); i++){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    a++;b++;
                }else{
                    a = max(0, a-1);
                    b--;
                }
            }else{
                a = max(0, a-1);
                b++;
            }
            if(b<0){
                return false;
            }
        }
        return a==0;
    }
};