class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    int steps = 0;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    q.push({ entrance[0], entrance[1] });
    vis[entrance[0]][entrance[1]] = 1;

    while (!q.empty()) {
        int sz = q.size();
        steps++;

        while (sz--) {
            auto top = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int x = top.first + dx[i], y = top.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.') {
                    q.push({x, y});
                    vis[x][y] = 1;
                    if ((x != entrance[0] || y != entrance[1]) && (x == 0 || y == 0 || x == m - 1 || y == n - 1))
                        return steps;
                }
            }
        }
    }

    return -1;
    }
};