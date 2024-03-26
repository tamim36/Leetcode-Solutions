class Solution {
public:
    bool check_isValidSudoku_by_Grid(int row, int col, vector<vector<int>>& rowValues, vector<vector<int>>& colValues, vector<vector<char>>& board) {
    unordered_set<int> st;
        
    for (int r = row; r < row + 3 && r < 9; r++) {
        for (int c = col; c < col + 3 && c < 9; c++) {
            int val = board[r][c] != '.' ? board[r][c] - '0' : 0;
            if (val > 0) {
                if (++rowValues[r][val] == 2 || ++colValues[c][val] == 2)
                    return false;

                if (st.count(val))
                    return false;

                st.insert(val);
            }
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rowValues(9, vector<int>(10, 0)), colValues(9, vector<int>(10, 0));

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!check_isValidSudoku_by_Grid(i, j, rowValues, colValues, board))
                return false;
        }
    }

    return true;
}
};