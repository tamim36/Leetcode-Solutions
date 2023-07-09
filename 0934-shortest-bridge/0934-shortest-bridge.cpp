class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
    vector<vector<int>> cal(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<pair<int, int>> one_group;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                q.push({i, j});
                cal[i][j] = 0;
                i = m;
                break;
            }
        }
    }

    while (!q.empty())
    {
        auto top = q.front(); q.pop();
        one_group.push_back(top);

        for (int i = 0; i < 4; i++) {
            int x = top.first + dx[i], y = top.second + dy[i];
            if (x < 0 || y < 0 || x >= m || y >= n)
                continue;
            else if (grid[x][y] && cal[x][y] == -1) {
                q.push({ x, y });
                cal[x][y] = 0;
            }
        }
    }

    for (auto one : one_group)
        q.push(one);

    int cnt = -1;
    while (!q.empty()) {
        int sz = q.size();
        cnt++;

        while (sz--) {
            auto top = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int x = top.first + dx[i], y = top.second + dy[i];
                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                if (cal[x][y] == -1) {
                    if (!grid[x][y]) {
                        q.push({ x, y });
                        cal[x][y] = 0;
                    }
                    else
                        return cnt;
                }
            }
        }
    }
    return cnt;
    }
};