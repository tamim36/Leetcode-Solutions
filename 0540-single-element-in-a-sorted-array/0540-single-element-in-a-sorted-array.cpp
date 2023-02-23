class Solution {
public:
    bool isRight(vector<int>& nums, int mid) {
    if (nums[mid] == nums[mid + 1]) {
        if (mid % 2 == 0) return false;
        else return true;
    } 
    else {
        if (mid % 2 == 1) return false;
        else return true;
    }
}

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int left = 0, right = n;

    while (right - left) {
        int mid = left + (right - left) / 2;

        if (isRight(nums, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return nums[left];
}
};