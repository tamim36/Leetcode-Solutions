class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int prevOne = -1;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (prevOne == -1) {
                    ans = 1;
                    prevOne = i;
                } else {
                    ans = (ans * (i - prevOne)) % (int)(1e9 + 7);
                    prevOne = i;
                }
            }
        }

        return ans % (int)(1e9 + 7);
    }
};