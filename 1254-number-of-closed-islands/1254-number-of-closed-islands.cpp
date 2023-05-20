class Solution {
public:
    void dfsClosedIsland(vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    if (grid[i][j] || vis[i][j]) return;
    vis[i][j] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int x = 0; x < 4; x++) {
        dfsClosedIsland(grid, vis, m, n, dx[x] + i, dy[x] + j);
    }
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int a = 0;

    for (int i = 0, r = 0; i < n; i++) {
        if (!vis[r][i] && !grid[r][i])
            dfsClosedIsland(grid, vis, m, n, r, i);

        if (i == n - 1 && r != m - 1) {
            r = m - 1;
            i = -1;
        }
            
    }

    for (int i = 0, c = 0; i < m; i++) {
        if (!vis[i][c] && !grid[i][c])
            dfsClosedIsland(grid, vis, m, n, i, c);

        if (i == m - 1 && c != n - 1) {
            c = n - 1;
            i = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && !grid[i][j]) {
                dfsClosedIsland(grid, vis, m, n, i, j);
                a++;
            }   
        }
    }

    return a;
}
};