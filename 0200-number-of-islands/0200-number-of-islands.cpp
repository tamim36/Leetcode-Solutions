class Solution {
public:
    void dfsNumIsland(vector<vector<char>>& grid, int m, int n, vector<vector<int>>& vis, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    int val = grid[i][j] - '0';
    if (!val || vis[i][j]) return;

    vis[i][j] = 1;
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int x = 0; x < 4; x++) {
        dfsNumIsland(grid, m, n, vis, dx[x] + i, dy[x] + j);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j] - '0';
            if (val && !vis[i][j]) {
                dfsNumIsland(grid, m, n, vis, i, j);
                cnt++;
            }
        }
    }

    return cnt;
}
};