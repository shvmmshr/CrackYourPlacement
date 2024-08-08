class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size();
        int n=needle.size();
        if (n==0) return 0;
        if (h<n) return -1;
        for (int i=0;i<=h-n;i++){
            if (haystack.substr(i,n)==needle) return i;
        }
        return -1;
    }
};