class Solution {
public:
    bool canPartition(vector<int>& nums, int curSum, int targetSum, int n, vector<vector<int>>& dp) {
    if (curSum == targetSum)
        return true;
    if (n <= 0 || targetSum < curSum)
        return false;
    if (dp[n][curSum] != -1)
        return dp[n][curSum];

    dp[n][curSum] = canPartition(nums, curSum + nums[n - 1], targetSum, n - 1, dp)
        || canPartition(nums, curSum, targetSum, n - 1, dp);

    return dp[n][curSum];
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>((sum/2) + 1, -1));
    return canPartition(nums, 0, sum/2, n, dp);
}
};