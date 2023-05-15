class Solution {
public:
    int mvMov = 0;
void dfsMaxMoves(vector<vector<int>>& grid, int m, int n, int r, int c, int prev, int mov) {
    if (r < 0 || c < 0 || r >= m || c >= n || !grid[r][c] || grid[r][c] <= prev) return;
    //cout << prev << "  ";
    prev = grid[r][c];
    grid[r][c] = 0;

    int dx[] = {-1, 0, 1};
    int dy[] = {1, 1, 1};
    ++mov;
    mvMov = max(mov, mvMov);
    for (int i = 0; i < 3; i++)
        dfsMaxMoves(grid, m, n, r+dx[i], c+dy[i], prev, mov);
}

int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
        dfsMaxMoves(grid, m, n, i, 0, 0, 0);
    }
    return mvMov-1;
}
};