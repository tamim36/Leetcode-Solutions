class Solution {
public:
    int count_setBits_ByFlipping(int n) {
    int count = 0;
    while (n) {
        n = n & n - 1;
        count++;
    }

    return count;
}

// 2220
int minBitFlips(int start, int goal) {
    int bitDifference = start ^ goal;
    return count_setBits_ByFlipping(bitDifference);
}
};