class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> zeroRow(r, 0), zeroCol(c, 0);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!matrix[i][j]) {
                    zeroRow[i] = 1;
                    zeroCol[j] = 1;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (zeroRow[i] || zeroCol[j])
                    matrix[i][j] = 0;
            }
        }
    }
};