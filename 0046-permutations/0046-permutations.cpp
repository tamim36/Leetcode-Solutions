class Solution {
public:
    void recurPermutation(vector<int>& nums, vector<vector<int>>& result, int i, int n) {
    if (i == n) {
        result.push_back(nums);
        return;
    }

    for (int j = i; j <= n; j++) {
        swap(nums[i], nums[j]);
        recurPermutation(nums, result, i+1, n);
        swap(nums[i], nums[j]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    recurPermutation(nums, result, 0, nums.size() - 1);

    return result;
}
};