#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int count = 32;
        while(count--){
            int i = n & 1;
            n >>= 1;
            result = result * 2 + i;
        }
        return result;
    }
};