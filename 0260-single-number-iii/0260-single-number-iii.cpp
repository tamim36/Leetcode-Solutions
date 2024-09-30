class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_two_num = 0;
for (int i = 0; i < nums.size(); i++) {
    xor_two_num ^= nums[i];
}

int right_bit = 1;
while (xor_two_num) {
    if (xor_two_num & 1)
        break;

    xor_two_num >>= 1;
    right_bit <<= 1;
}

int a = 0, b = 0;
for (int i = 0; i < nums.size(); i++) {
    if (right_bit & nums[i])
        a ^= nums[i];
    else
        b ^= nums[i];
}

return {a, b};
    }
};