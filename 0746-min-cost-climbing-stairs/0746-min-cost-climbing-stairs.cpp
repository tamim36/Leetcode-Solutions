class Solution {
public:
    int dp[1002];

int recur_minCostClimbingStairs(vector<int>& cost, int idx) {
    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    //cout << idx << endl;
    dp[idx] = cost[idx] + min(recur_minCostClimbingStairs(cost, idx-1), 
        recur_minCostClimbingStairs(cost, idx - 2));

    return dp[idx];
}

int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    int n = cost.size();
    memset(dp, -1, sizeof(dp));

    return recur_minCostClimbingStairs(cost, n - 1);
}
};