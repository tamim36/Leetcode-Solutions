class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        int row = n, col = n;
    long long sum = 0;
    vector<int> row_vis(n, 0), col_vis(n, 0);

    for (int i = q.size() - 1; i >= 0; i--) {
        int type = q[i][0], ind = q[i][1], val = q[i][2];

        if (type && !col_vis[ind]) {
            sum += col * val;
            row--;
            col_vis[ind] = 1;
        }

        else if (!type && !row_vis[ind]) {
            sum += row * val;
            col--;
            row_vis[ind] = 1;
        }
    }

    return sum;
    }
};