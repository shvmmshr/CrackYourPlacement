class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,r=k-1;
        int sum=0;
        for(int i=l;i<=r;i++){
            sum+=nums[i];
        }
        int maxsum=sum;
        l++;
        r++;
        while(r<nums.size()){
            sum+=nums[r];
            sum-=nums[l-1];
            maxsum=max(maxsum,sum);
            l++;
            r++;
        }
        return (double)maxsum/k;
    }
};