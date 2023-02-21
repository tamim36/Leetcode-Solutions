class Solution {
public:
    bool isValidminimumSize(vector<int>& nums, int mid, int op) {
    int cnt = 0;

    for (auto num : nums) {
        if (num > mid) cnt += (num - 1) / mid;
    }

    return cnt <= op;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isValidminimumSize(nums, mid, maxOperations))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}
};