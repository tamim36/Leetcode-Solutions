class Solution {
public:
    int MinCostTicketsDP(int startDay, int idx, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp) {
    if (idx <= 0 || startDay < 0)
        return 0;

    if (dp[idx][startDay] != -1)
        return dp[idx][startDay];

    if (days[idx - 1] >= startDay)
        return dp[idx][startDay] = MinCostTicketsDP(startDay, idx - 1, days, costs, dp);
    else {
        int a = costs[0] + MinCostTicketsDP(days[idx - 1], idx - 1, days, costs, dp);
        int b = costs[1] + MinCostTicketsDP(days[idx - 1] - 7 + 1, idx - 1, days, costs, dp);
        int c = costs[2] + MinCostTicketsDP(days[idx - 1] - 30 + 1, idx - 1, days, costs, dp);
        
        return dp[idx][startDay] = min(a, min(b, c));
    }
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<vector<int>> dp(days.size() + 1, vector<int>(367, -1));
    return MinCostTicketsDP(366, days.size(), days, costs, dp);
}
};