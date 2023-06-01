class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dis(m, vector<int>(n, -1));
    queue<pair<int, int>> q;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) {
                q.emplace(i, j);
                dis[i][j] = 0;
            } 
        }
    }

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int x = r + dx[i], y = c + dy[i];
            if (x >= 0 && y >= 0 && x < m && y < n && dis[x][y] == -1) {
                q.emplace(x, y);
                dis[x][y] = dis[r][c] + 1;
            }
        }
    }

    return dis;
    }
};