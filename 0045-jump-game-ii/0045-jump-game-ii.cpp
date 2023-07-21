class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        if (n <= 2)
            return n-1;

    for (int i = 0; i < n; i++) {
        int len = i + nums[i] + 1;
        len = min(len, n);
        if (len == n)
            return cnt + 1;
        int mx = -1;
        for (int j = i + 1; j < len; j++) {
            if (j + nums[j] >= mx) {
                mx = j + nums[j];
                i = j - 1;
            }
        }
        cnt++;
    }
    return cnt - 1;
    }
};