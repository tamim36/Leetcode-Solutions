class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0]) return k;
    int n = arr.size();
    if (k > arr[n - 1] - n) return k + n;
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] - (mid + 1) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    //int res = (k - (arr[left - 1] - left)) + arr[left - 1];
    return k + left; 
    }
};