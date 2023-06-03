class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int lvl = 0, n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1]) return -1;
    if (n <= 1) return 1;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    vis[0][0] = 1;

    int dx[] = { 1,1, 1,-1,-1,-1,0, 0 };
    int dy[] = { 1,0,-1, 1, 0,-1,1,-1 };

    while (!q.empty()) {
        int qsz = q.size();
        lvl++;
        while (qsz--)
        {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 8; i++) {
                int rd = r + dx[i], cd = c + dy[i];

                if (rd >= 0 && cd >= 0 && rd < n && cd < n && !vis[rd][cd] && !grid[rd][cd]) {
                    if (rd == n - 1 && cd == n - 1)
                        return lvl + 1;
                    q.emplace(rd, cd);
                    vis[rd][cd] = 1;
                }
            }
        }
    }

    return -1;
    }
};