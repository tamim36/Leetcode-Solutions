class Solution {
public:
    int binarySearchToCountSmaller(vector<int>& vec, int val) {
    int left = 0, right = vec.size();

    if (vec[left] > val) return left;
    if (vec[right - 1] < val) return right;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] > val)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

bool isThereMorethanKth(vector<vector<int>>& mat, int k, int mid) {
    int cnt = 0;

    for (int i = 0; i < mat.size(); i++) {
        cnt += binarySearchToCountSmaller(mat[i], mid);

        if (cnt >= k) return true;
    }

    return false;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isThereMorethanKth(matrix, k, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
};