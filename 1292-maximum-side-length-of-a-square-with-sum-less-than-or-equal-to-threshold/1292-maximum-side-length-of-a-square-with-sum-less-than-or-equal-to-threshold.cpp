class Solution {
public:
    int minV = INT_MAX;
bool isValidMaxValue(vector<vector<int>>& mat, int mid, int t) {
    if (mid == 1)
        if (minV <= t) 
            return true;
        else
            return false;

    for (int row = mid-1.; row < mat.size(); row++) {
        for (int col = mid-1; col < mat[0].size(); col++) {
            /*int a = mat[row][col];
            int b = (row - mid) >= 0 ? mat[row - mid][col] : 0;
            int c = (col - mid) >= 0 ? mat[row][col - mid] : 0;
            int d = (row - mid) >= 0 && (col - mid) >= 0 ? mat[row - mid][col - mid] : 0;
            int val = a - b - c + d;*/
            int val = mat[row][col]
                - ((row - mid) >= 0 ? mat[row - mid][col] : 0) 
                - ((col - mid) >= 0 ? mat[row][col - mid] : 0)
                + ((row - mid) >= 0 && (col - mid) >= 0 ? mat[row - mid][col - mid] : 0);

            if (val <= t) return true;
        }
    }

    return false;
}

// 1292
int maxSideLength(vector<vector<int>>& mat, int threshold) {
    // 2d prefix sum
    
    for (int row = 0; row < mat.size(); row++) {
        for (int col = 0; col < mat[row].size(); col++) {
            minV = min(minV, mat[row][col]);
            mat[row][col] += (row > 0 ? mat[row - 1][col] : 0) 
                + (col > 0 ? mat[row][col - 1] : 0)
                - (row > 0 && col > 0 ? mat[row - 1][col - 1] : 0);
        }
    }

    int left = 1, right = min(mat.size(), mat[0].size()) + 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (!isValidMaxValue(mat, mid, threshold))
            right = mid;
        else
            left = mid + 1;
    }

    return left - 1;
}
};