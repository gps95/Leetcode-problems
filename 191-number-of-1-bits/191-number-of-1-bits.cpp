#include <bit>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __popcount(n);
    }
};