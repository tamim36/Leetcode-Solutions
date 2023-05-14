class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        //cout << grid[0][61] << endl;
        int dx[] = { -1, 0, 1 };
        int dy[] = { 1, 1, 1 };
        int m = grid.size(), n = grid[0].size();
    int mx = 0, lvl = 0;;

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        q.push({i, 0});

        while (!q.empty())
        {
            int sz = q.size();
            lvl++;
            for (int j = 0; j < sz; j++) {
                auto top = q.front(); q.pop();
                int a = top.first, b = top.second;
                //cout << a << "  " << b << endl;
                if (!grid[a][b])
                    continue;
                int prev = grid[a][b];
                grid[a][b] = 0;

                

                for (int i = 0; i < 3; i++) {
                    int r = a + dx[i], c = b + dy[i];
                    
                    
                    if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] && grid[r][c] > prev) {
                        //cout << "r " << r << "  c  " << c << " m " << m << " n " << n << endl;
                        q.push({ r, c });
                    }
                }
            }
        }

        mx = max(lvl-1, mx);
        if (mx == n - 1) return mx;
        lvl = 0;
    }
    return mx;
    }
};