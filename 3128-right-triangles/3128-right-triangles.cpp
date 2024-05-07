class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rsz = grid.size(), csz = grid[0].size();
vector<int> rowSum(rsz, 0), colSum(csz, 0);

for (int r = 0; r < rsz; r++) {
    for (int c = 0; c < csz; c++) {
        rowSum[r] += grid[r][c];
        colSum[c] += grid[r][c];
    }
}

long long cnt = 0;

for (int r = 0; r < rsz; r++) {
    for (int c = 0; c < csz; c++) {
        if (grid[r][c]) {
            cnt += ((rowSum[r] - 1) * (colSum[c] - 1));
        }
    }
}

return cnt;
    }
};