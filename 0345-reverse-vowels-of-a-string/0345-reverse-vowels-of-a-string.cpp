class Solution {
public:
    void swap(int i, int j, string &s){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        string a="aeiouAEIOU";
        map<char,int> m;
        for(auto c:a){
            m[c]=1;
        }
        while(i<j){
            if(m[s[i]]==1 && m[s[j]]==1){
                swap(i,j,s);
                i++;
                j--;
            }
            if(m[s[i]]!=1){
                i++;
            }
            if(m[s[j]]!=1){
                j--;
            }
        }
        return s;
    }
};