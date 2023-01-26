class Solution {
public:
    // using binary search
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size();
    sort(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > mid) right = mid;
        else left = mid + 1;
    }
    return left;
    }
};