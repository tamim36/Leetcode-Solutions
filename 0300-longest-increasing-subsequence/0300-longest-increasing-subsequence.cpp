class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size(), mxLenLis = 1;
vector<int> lis(sz, 1);

for (int i = 1; i < sz; i++) {
    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
            lis[i] = max(lis[i], lis[j] + 1);
            mxLenLis = max(mxLenLis, lis[i]);
        }
    }
}

return mxLenLis;
    }
};