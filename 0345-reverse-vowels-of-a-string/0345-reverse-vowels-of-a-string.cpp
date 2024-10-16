
class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }else if(isVowel(s[i])){
                j--;
            }else{
                i++;
            }
        }
        return s; 
    }
};