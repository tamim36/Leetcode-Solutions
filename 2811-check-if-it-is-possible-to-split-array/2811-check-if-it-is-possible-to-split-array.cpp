class Solution {
public:
    bool isSpliArray = false;
bool recurCanSplitArray(vector<int>& nums, vector<vector<int>>& dp, int start, int end, int sum, int m) {
    if (isSpliArray)
        return true;

    if (dp[start][end-1] != -1)
        return dp[start][end] == 1 ? true : false;

    if (sum < m) {
        dp[start][end-1] = 0;
        return false;
    }

    if (end - start <= 2) {
        isSpliArray = true;
        dp[start][end-1] = 1;
        return true;
    }
    bool left = recurCanSplitArray(nums, dp, start + 1, end, sum - nums[start], m);
    bool right = recurCanSplitArray(nums, dp, start, end - 1, sum - nums[end - 1], m);

    if (left || right)
        dp[start][end-1] = 1;
    else
        dp[start][end-1] = 0;

    return dp[start][end-1];
}


bool canSplitArray(vector<int>& nums, int m) {
    int sz = nums.size();
    if (sz <= 2)
        return true;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if (sum < m)
        return false;

    vector<vector<int>> dp(sz, vector<int>(sz, -1));
    return recurCanSplitArray(nums, dp, 0, sz, sum, m);
}
};