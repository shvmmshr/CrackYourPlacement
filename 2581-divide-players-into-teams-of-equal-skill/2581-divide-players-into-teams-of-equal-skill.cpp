class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        long long temp=skill[i]+skill[j];
        long long sum=0;
        while(i<j){
            if(skill[i]+skill[j]==temp) sum+=skill[i]*skill[j];
            else return -1;
            i++;
            j--;
        }
        return sum;
    }
};