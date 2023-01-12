class Solution {
public:
    uint32_t reverseBits(uint32_t v) {
        unsigned int r = v; // r will be reversed bits of v; first get LSB of v
        int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end

        for (v >>= 1; v; v >>= 1){   
          r <<= 1;
          r |= v & 1;
          s--;
        }
        r <<= s; // shift when v's highest bits are zero
        return r;
    }
};