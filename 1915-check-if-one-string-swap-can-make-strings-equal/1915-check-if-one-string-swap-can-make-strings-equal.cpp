class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int count=0;
        int idx1,idx2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count==1){
                    idx1=i;
                }
                else if(count==2){
                    idx2=i;
                }
                else return false;
            }
        }
        if(count==0 || (s1[idx1]==s2[idx2] && s1[idx2]==s2[idx1])) return true;
        return false;
    }
};