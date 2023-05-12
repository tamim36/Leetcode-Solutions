class Solution {
public:
    void dfsMarkVis(vector<vector<char>>& board, vector<vector<int>>& vis, int r, int c, int m, int n, bool isMarkX) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (board[r][c] == 'X' || vis[r][c]) return;
    vis[r][c] = 1;
    if (isMarkX) board[r][c] = 'X';

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsMarkVis(board, vis, r + dx[i], c + dy[i], m, n, isMarkX);
        
        return;
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n;) {
            
            if (board[r][c] == 'O' && !vis[r][c])
                dfsMarkVis(board, vis, r, c, m, n, false);

            if (r == 0 || r == m - 1 || c == n - 1) c++;
            else c = n - 1;
        }
    }

    for (int r = 1; r < m - 1; r++) {
        for (int c = 1; c < n - 1; c++) {
           
            if (board[r][c] == 'O' && !vis[r][c])
                dfsMarkVis(board, vis, r, c, m, n, true);
        }
    }
}
};