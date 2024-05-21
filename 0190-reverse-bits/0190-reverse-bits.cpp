class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0)
    return n;
       uint32_t rev = 0;
int i = 0;

while (n) {
    rev <<= 1;
    if (n & 1) 
        rev |= 1;
    i++;
    n >>= 1;
}

return rev << (32 - i);
    }
};