class Solution {
public:
    bool isUgly(int n) {
        if(n==1)    return true;
        if(n==0 || n%5!=0 && n%3!=0 && n%2!=0)  return false;

        if(n%5==0)  n=n/5;
        if(n%3==0)  n=n/3;
        if(n%2==0)  n=n/2;

        return isUgly(n);
    }
};