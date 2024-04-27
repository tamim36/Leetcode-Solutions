class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> bits(32, 0);

for (auto num : nums) {
    int idx = 0;
    while (num) {
        if (num & 1)
            bits[idx]++;

        idx++;
        num = num >> 1;
    }
}

long long pos = 1;
int val = 0;
for (int i = 0; i < bits.size(); i++) {
    if (bits[i] >= k)
        val += pos * 1;
    pos *= 2;
}

return val;
    }
};