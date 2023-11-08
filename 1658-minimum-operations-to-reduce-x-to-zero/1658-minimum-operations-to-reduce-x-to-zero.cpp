class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long tot = accumulate(nums.begin(), nums.end(), 0);
int sz = nums.size();
long long rem = tot - x;
int maxWindow = 0, curWindow = 0, curSum = 0;

if (tot == x) return sz;
if (tot < x) return -1;

curSum = nums[0];
for (int i = 0, j = 1; j < sz; ) {
    if (curSum == rem)
        maxWindow = max(maxWindow, j - i);

    if (curSum <= rem)
        curSum += nums[j++];
    while (curSum > rem && i < j)
        curSum -= nums[i++];
    if (curSum == rem)
        maxWindow = max(maxWindow, j - i);
    //cout << curSum << endl;
}

return maxWindow == 0 ? -1 : sz - maxWindow;
    }
};