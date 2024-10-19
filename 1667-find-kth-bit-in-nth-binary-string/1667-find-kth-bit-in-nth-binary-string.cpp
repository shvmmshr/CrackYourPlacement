class Solution {
public:
    string invert(string x){
        string res="";
        for(char c:x){
            if(c=='1') res+='0';
            else res+='1';
        }
        return res;
    }
    char findKthBit(int n, int k) {
        string res="";
        res+="0";
        for(int i=1;i<=n;i++){
            if(res.size()>k) break;
            string x=invert(res);
            reverse(x.begin(),x.end());
            res+="1"+x;
        }
        return res[k-1];
    }
};