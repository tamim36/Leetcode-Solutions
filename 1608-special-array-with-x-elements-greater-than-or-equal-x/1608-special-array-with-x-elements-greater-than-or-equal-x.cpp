class Solution {
public:
    int isValidSpecial(int x, vector<int>& nums) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x <= nums[mid])
            right = mid;
        else
            left = mid + 1;
    }
    // here left = minimum index
    int diff = nums.size() - left;
    if (x == diff) return 1;
    else if (x < diff) return 2; // increase x value
    else return 0; // decrease x value
}

int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if (nums[nums.size() - 1] == 0) return -1;
    int left = 1, right = nums.size() + 1;
    int mid = -1;
    while (left < right) {
        mid = left + (right - left) / 2;
        int val = isValidSpecial(mid, nums);
        if (val == 1) return mid;
        else if (val == 0)
            right = mid;
        else
            left = mid + 1;
    }

    return -1;
}
};