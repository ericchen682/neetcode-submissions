class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 1 means 32nd bit
        // 2 means 31st bit
        // 3 means 30th bit
        uint32_t res = 0;
        for(int i = 0; i < 32; i++)
        {
            if(n & 1) res++;
            n = n >> 1;
            if(i != 31)
            res = res << 1;
        }
        return res;
    }
};
