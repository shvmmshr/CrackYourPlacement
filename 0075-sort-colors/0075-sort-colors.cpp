class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size();i++){
            if (nums[i]==0) a+=1;
            if (nums[i]==1) b+=1;
            if (nums[i]==2) c+=1;
        }
        for(int i=0;i<a;i++) nums[i]=0;
        for(int i=a;i<a+b;i++) nums[i]=1;
        for(int i=a+b;i<a+b+c;i++) nums[i]=2;
    }
};