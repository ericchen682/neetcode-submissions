class Solution {
public:
    int getSum(int a, int b) {
        // add xor and then and shifted left 1
        if(a == 0) return b;
        return getSum((a&b)<<1, a^b);
    }
};
