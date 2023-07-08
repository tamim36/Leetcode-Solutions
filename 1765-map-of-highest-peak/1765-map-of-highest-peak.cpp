class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& maze) {
    int m = maze.size(), n = maze[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    int steps = 0;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (maze[i][j])
                q.push({ i, j }), ans[i][j] = 0;
    }

    while (!q.empty()) {
        int sz = q.size();
        steps++;

        while (sz--) {
            auto top = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int x = top.first + dx[i], y = top.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    q.push({ x, y });
                    ans[x][y] = steps;
                }
            }
        }
    }

    return ans;
}
};