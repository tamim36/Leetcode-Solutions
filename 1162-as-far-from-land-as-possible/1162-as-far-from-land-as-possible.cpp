class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int mx = -1, m = grid.size(), n = grid[0].size();
    vector<vector<int>> mat(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                q.emplace(i, j);
                mat[i][j] = 0;
            }
        }
    }

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int rx = r + dx[i], cy = c + dy[i];

            if (rx >= 0 && cy >= 0 && rx < m && cy < n && !grid[rx][cy] && mat[rx][cy] == -1) {
                mat[rx][cy] = mat[r][c] + 1;
                mx = max(mx, mat[rx][cy]);
                q.emplace(rx, cy);
            }
        }
    }

    return mx;
    }
};