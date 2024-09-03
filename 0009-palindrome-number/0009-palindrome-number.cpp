class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        long long sum=0;
        while(n>0){
            sum=sum*10+n%10;
            n=n/10;
        }
        if(x==sum) return true;
        return false;
    }
};