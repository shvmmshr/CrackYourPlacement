class Solution {
public:
    void generate(string &n, int k) {
        while(n.size()<=k) {
            string temp=n;
            for(int i=0;i<temp.size();i++) {
                temp[i]=temp[i]+1;
            }
            n=n+temp;
        }
    }
    char kthCharacter(int k) {
        string n="a";
        generate(n,k);
        return n[k-1];
    }
};