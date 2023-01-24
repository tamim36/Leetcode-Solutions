class Solution {
public:
    bool isSmallesDivisor(int divisor, vector<int>& nums, int threshold) {
    int res = 0;
    for (auto num : nums) {
        res += ceil(double(num) / double(divisor));
        if (res > threshold)
            return false;
    }

    return res <= threshold;
}

// 1283
int smallestDivisor(vector<int>& nums, int threshold) {
    int right = 0, left = 1;
    for (auto num : nums)
        right = max(num, right);

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isSmallesDivisor(mid, nums, threshold))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
};