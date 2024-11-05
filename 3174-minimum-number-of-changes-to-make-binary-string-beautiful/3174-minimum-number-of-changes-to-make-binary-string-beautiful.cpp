class Solution {
public:
    int minChanges(string s) {
        int l=0;
        int res=0;
        for(int r=0;r<=s.size();r++){
            if(s[l]!=s[r]){
                if(r%2==1) res++;
                l=r;
            }
        }

        return res;
    }
};
