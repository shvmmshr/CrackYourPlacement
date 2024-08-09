class Solution {
public:
    bool isPalindrome(string s, int l ,int r){
        int m=1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(s[i]!=s[j]){
                return (isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1));
            }
        }
        return true;
    }
};