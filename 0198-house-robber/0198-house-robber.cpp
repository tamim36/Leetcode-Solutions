class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = nums[0], eve = 0;

    for (int i = 1; i < nums.size(); i++) {
        if ((i + 1) % 2)
            odd = nums[i] + max(odd, (eve - nums[i - 1]));
        else
            eve = nums[i] + max(eve, (odd - nums[i - 1]));
    }

    return max(odd, eve);
    }
};