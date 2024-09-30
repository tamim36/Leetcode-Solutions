class Solution {
public:
    int dp_minPathSum(vector<vector<int>>& grid, int row, int col, int i, int j, vector<vector<int>>& dp) {
        if (i >= row || j >= col || i < 0 || j < 0)
    return INT_MAX;

    if (i == 0 && j == 0)
        return grid[i][j];
        
    if (dp[i][j] != 0)
        return dp[i][j];

    dp[i][j] = grid[i][j] + min(dp_minPathSum(grid, row, col, i - 1, j, dp),
                                dp_minPathSum(grid, row, col, i, j-1, dp));
    return dp[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int val = dp_minPathSum(grid, row, col, row-1, col-1, dp);
    return val;
}
};