class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
vector<int> count(n + 1, 0);
vector<int> ans(2, 0);

for (int i = 0; i < n; i++) {
    ans[1] ^= (i + 1) ^ nums[i];
    if (++count[nums[i]] == 2)
        ans[0] = nums[i];
}

ans[1] ^= ans[0];
return ans;
    }
};