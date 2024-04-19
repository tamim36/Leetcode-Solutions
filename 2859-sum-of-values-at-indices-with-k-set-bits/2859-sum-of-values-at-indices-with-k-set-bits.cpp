class Solution {
public:
    int count_setBits(int n) {
    int count = 0;

    while (n) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (count_setBits(i) == k)
            sum += nums[i];
    }

    return sum;
}

};