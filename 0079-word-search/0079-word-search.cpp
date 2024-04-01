class Solution {
public:
    bool recur_exist(int row, int col, string sofar, vector<vector<int>>& vis, vector<vector<char>>& board, string word) {
    //cout << sofar << endl;
    if (sofar == word) {
        return true;
    }
    if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0)
        return false;

    int idx = sofar.size() - 1;
    if (idx > 0 && idx < sofar.size() && idx < word.size() && sofar[idx] != word[idx])
        return false;

    int dx[] = { 1, -1, 0,  0 };
    int dy[] = { 0,  0, 1, -1 };

    for (int i = 0; i < 4; i++) {
        int r = row + dx[i], c = col + dy[i];
        if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0 || vis[r][c])
            continue;

        vis[r][c] = 1;
        sofar.push_back(board[r][c]);
        if (recur_exist(r, c, sofar, vis, board, word)) return true;
        sofar.pop_back();
        vis[r][c] = 0;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            string a = string(1, word[0]);
            cout << a << endl;
            if (board[i][j] == word[0]) {
                
                vis[i][j] = 1;
                if (recur_exist(i, j, string(1, word[0]), vis, board, word))
                    return true;
                vis[i][j] = 0;
            }
        }
    }

    return false;
}
};