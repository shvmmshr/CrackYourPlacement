class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> k;
        while(i<j){
            if((numbers[i]+numbers[j])==target) {
                k.push_back(i+1);
                k.push_back(j+1);
            }
            if(numbers[i]+numbers[j]>target) j--;
            else i++;
        }
        return k;
    }
};