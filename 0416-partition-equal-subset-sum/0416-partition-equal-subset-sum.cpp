class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // top down approach
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int n = nums.size();
        int targetSum = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));


        for (int i = 0; i < n + 1; i++)
            dp[i][0] = true;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < targetSum + 1; j++) {
                if (j - nums[i-1] >= 0)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][targetSum];
    }
};