class Solution {
public:
    bool isValidMinimizeMax(vector<int>& nums, int p, int x) {
    for (int i = 0; p > 0 && i < nums.size()-1; i++) {
        if ((nums[i + 1] - nums[i]) <= x) {
            
            p--;
            i++;
        }
    }
    if (p <= 0)
        return true;
    else
        return false;
}

int minimizeMax(vector<int>& nums, int p) {
    if (!p || nums.empty())
        return 0;

    sort(nums.begin(), nums.end());

    int sz = nums.size(), left = 0, right = (nums[sz-1] - nums[0] + 1);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValidMinimizeMax(nums, p, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}
};