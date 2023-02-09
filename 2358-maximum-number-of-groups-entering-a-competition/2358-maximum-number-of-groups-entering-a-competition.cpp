class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int left = 0, right = 1000, n = grades.size();

    while (left < right) {
        int mid = 1 + left + (right - left) / 2;
        if (mid * (mid + 1) / 2 > n)
            right = mid-1;
        else
            left = mid;
    }
    return left;
    }
};