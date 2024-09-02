class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int len=chalk.size();
        long long total=0;
        for(int j=0;j<len;j++){
            total+=chalk[j];
        }
        k=k%total;
        for(int i=0;i<len;i++){
            if(k<chalk[i]) return i;
            k=k-chalk[i];
        }
        return 0;
    }
};