class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
vector<vector<int>> isConn(n, vector<int>(n, 0));

for (int i = 0; i < roads.size(); i++) {
    int x = roads[i][0], y = roads[i][1];
    adj[y].push_back(x);
    adj[x].push_back(y);
    isConn[x][y] = 1, isConn[y][x] = 1;
}

int max_rank = 0;

for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        int cur_rank = adj[i].size() + adj[j].size();
        if (isConn[i][j])
            cur_rank--;

        max_rank = max(max_rank, cur_rank);
    }
}



return max_rank;
    }
};