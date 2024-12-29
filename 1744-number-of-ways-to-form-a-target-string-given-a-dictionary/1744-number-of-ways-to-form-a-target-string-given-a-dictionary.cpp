class Solution {
public:
    int dp[1001][1001];
    int MOD = 1e9 + 7;

    int func(vector<vector<int>>& freq, string target, int n, int index, int target_index){
        if(target_index >= target.size()){
            return 1;
        }
        if(index >= n || n - index < target.size() - target_index){
            return 0;
        }

        // Check if value already present
        if(dp[index][target_index] != -1){
            return dp[index][target_index];
        }

        // find occurence of the letter
        long long occurance = freq[index][target[target_index] - 'a'];

        // if the letter is present at the index of any array then we have two options, either take it or not. Else we have only one option to not take it. 
        if(occurance){
            long long with = occurance * func(freq, target, n, index + 1, target_index + 1);
            long long without = func(freq, target, n, index + 1, target_index);
            dp[index][target_index] = (with + without) % MOD;
        } else {
            long long without = func(freq, target, n, index + 1, target_index);
            dp[index][target_index] = without % MOD;
        }

        // return the current value to store it in our cache
        return dp[index][target_index];

    }
    int numWays(vector<string>& words, string target) {
        // Initialisation
        int n = words[0].size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> freq(n, vector<int>(26, 0));

        // make frequency array to check if the char is present at that index
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words.size(); j++){
                freq[i][words[j][i] - 'a']++;
            }
        }
        
        return func(freq, target, n, 0, 0);
    }
};