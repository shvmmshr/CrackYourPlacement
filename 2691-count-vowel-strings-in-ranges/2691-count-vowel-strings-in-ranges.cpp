class Solution {
public:
    int isVowel(char ch){
        string str = "aeiou";
        return (str.find(ch) != string::npos);
    }   
    vector<int> vowelStrings(vector<string>& A, vector<vector<int>>& Q) {
        int n = A.size();
        vector<int> Pre(n,0);
        for(int i=0;i<n;i++){
            string temp = A[i];
            if(isVowel(temp[0]) && isVowel(temp[temp.size()-1])){
                Pre[i]++;
            }
        }
        for(int i=1;i<n;i++){
            Pre[i] += Pre[i-1];
        }
        vector<int> ans;
        for(auto it : Q){
            int l = it[0];
            int r = it[1];
            if(l==0){ 
                ans.push_back(Pre[r]);
            }else{
                ans.push_back(Pre[r] - Pre[l-1]);
            }
        }
        return ans;


    }
};