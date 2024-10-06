class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target, int curSum, int n) {
    if (target == curSum && n == 0)
        return 1;
    if (n <= 0)
        return 0;

    return findTargetSumWays(nums, target, curSum - nums[n - 1], n - 1)
        + findTargetSumWays(nums, target, curSum + nums[n - 1], n - 1);
}

int findTargetSumWays(vector<int>& nums, int target) {
    return findTargetSumWays(nums, target, 0, nums.size());
}
};