class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > 0)
            right = mid;
        else
            left = mid + 1;
    }

    int posNumbers = nums.size() - left;

    while (left > 0 && nums[left - 1] >= 0) {
        left--;
    }


    return max(left, posNumbers);
    }
};