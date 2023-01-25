class Solution {
public:
    bool bsToFindDistanceValue(int down, int up, vector<int>& arr2, int d) {
    int left = 0, right = arr2.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr2[mid] > up)
            right = mid;
        else if (arr2[mid] < down)
            left = mid + 1;
        else
            return false;
    }
    return true;
}

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int count = 0;
    for (auto num : arr1) {
        int down = min((num - d), (num + d));
        int up = max((num - d), (num + d));
        if (bsToFindDistanceValue(down, up, arr2, d)) count++;
    }

    return count;
}
};