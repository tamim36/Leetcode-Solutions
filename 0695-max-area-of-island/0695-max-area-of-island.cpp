class Solution {
public:
        int dfsTomaxAreaOfIsland(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
    if (vis[r][c] || !grid[r][c]) return 0;
    vis[r][c] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    int size = 1;

    for (int i = 0; i < 4; i++)
        size += dfsTomaxAreaOfIsland(grid, vis, r + dx[i], c + dy[i]);

    return size;
}

int maxAreaOfIsland(vector<vector<int>> grid) {
    int r = grid.size(), c = grid[0].size(), maxi = 0;
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (!vis[r][c] && grid[r][c]) {
                maxi = max(maxi, dfsTomaxAreaOfIsland(grid, vis, r, c));
            }
        }
    }

    return maxi;
}
};