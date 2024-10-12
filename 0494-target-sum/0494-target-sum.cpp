class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (target < 0) target *= (-1);
int n = nums.size();
int sum = accumulate(nums.begin(), nums.end(), 0);

if ((target + sum) % 2)
    return 0;

int t = (target + sum) / 2;
vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

for (int i = 0; i < n; i++)
    dp[i][0] = 1;

for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= t; j++) {
        if (j - nums[i - 1] >= 0)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        else
            dp[i][j] = dp[i - 1][j];
    }
}

return dp[n][t];
    }
};