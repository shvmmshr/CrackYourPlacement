class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string res="";
        int digitA=0;
        int digitB=0;
        for(int i=0;i<max(a.size(),b.size());i++){
            if(i<a.size()) digitA=a[a.size()-1-i]-'0';
            else digitA=0;
            if(i<b.size()) digitB=b[b.size()-1-i]-'0';
            else digitB=0;
            res.append(to_string((digitA+digitB+carry)%2));
            carry=(digitA+digitB+carry)/2;
        }
        if(carry==1) res.append("1");
        reverse(res.begin(),res.end());
        return res;
    }
};