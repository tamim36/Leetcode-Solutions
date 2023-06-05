class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int f_idx = 0, l_idx = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1)
            f_idx = i;

        if (nums[i] == n)
            l_idx = i;

        if (f_idx && l_idx)
            break;
    }

    int ans = f_idx + n - l_idx-1;

    return f_idx > l_idx ? ans - 1 : ans;
    }
};