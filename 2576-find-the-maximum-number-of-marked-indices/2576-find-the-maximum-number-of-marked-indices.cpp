class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        if (nums.size() == 1) return 0;
    sort(nums.begin(), nums.end());
    int cnt = 0, n = nums.size();

    for (int i = 0, j = (n + 1) / 2; i < (n+1)/2; i++) {
        while (j < n) {
            if (2 * nums[i] <= nums[j]) {
                cnt += 2;
                j++;
                break;
            }
            else
                j++;
        }
    }

    return cnt;
    }
};