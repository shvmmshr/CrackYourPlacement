class Solution {
public:
    int minimizeXor(int x, int y) {
        int b = __builtin_popcount(y), res = 0;
        for(int i = 31; i >= 0 && b; i--)
            if(x & (1 << i)) b--, res |= (1 << i);
        for(int i = 0; i <= 31 && b; i++)
            if((res & (1 << i)) == 0) b--, res |= (1 << i);
        return res;
    }
};