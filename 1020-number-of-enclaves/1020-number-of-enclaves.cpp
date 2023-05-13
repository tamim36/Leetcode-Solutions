class Solution {
public:
    void dfsNumEnclaves(vector<vector<int>>& grid, int m, int n, int r, int c) {
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1) return;
    grid[r][c] = 2;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsNumEnclaves(grid, m, n, r+dx[i], c+dy[i]);
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n;) {
            dfsNumEnclaves(grid, m, n, r, c);

            if (r == 0 || r == m - 1 || c == n - 1) c++;
            else c = n - 1;
        }
    }

    int ans = 0;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) ans++;
        }
    }

    return ans;
}
};