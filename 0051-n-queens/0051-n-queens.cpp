class Solution {
public:
    bool validQueenPos(int row, int col, vector<pair<int, int>>& sofar) {
    int dx[] = { 1, 1, -1, -1 };
    int dy[] = { 1, -1, 1, -1 }; // for corners

    for (int i = 0; i < sofar.size(); i++) {
        int rq = sofar[i].first, cq = sofar[i].second;

        // check row & col
        if (rq == row || cq == col)
            return false;

        // check corner
        int diff = abs(rq - row);
        for (int d = 0; d < 4; d++) {
            int dxd = dx[d] * diff;
            int dyd = dy[d] * diff;

            if (dxd + rq == row && dyd + cq == col)
                return false;
        }
    }

    return true;
}

void backtrack_solveNQueen(int curRow, int n, vector<pair<int, int>>& sofar, vector<vector<pair<int, int>>>& results) {
    if (sofar.size() == n)
        results.push_back(sofar);

    for (int row = curRow, col = 0; col < n && row < n; col++) {
        if (validQueenPos(row, col, sofar)) {
            sofar.push_back({row, col});
            backtrack_solveNQueen(curRow + 1, n, sofar, results);
        }
    }

    if (!sofar.empty())
        sofar.pop_back();
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> board (n, vector<int>(n, 0));
    vector<pair<int, int>> sofar;
    vector<vector<pair<int, int>>> results;

    backtrack_solveNQueen(0, n, sofar, results);

    int resSz = results.size();
    string str(n, '.');
    vector<vector<string>> ans(resSz, vector<string>(n, str));

    for (int ansNo = 0; ansNo < resSz; ansNo++) {
        for (int rowCol = 0; rowCol < results[ansNo].size(); rowCol++) {
            int row = results[ansNo][rowCol].first, col = results[ansNo][rowCol].second;

            ans[ansNo][row][col] = 'Q';
        }
    }

    return ans;
}
};