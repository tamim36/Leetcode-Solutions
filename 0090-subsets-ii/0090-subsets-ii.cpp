class Solution {
public:
    void recur_subsetWithDup(int curIdx ,vector<int>& nums, vector<int>& sofar, vector<vector<int>>& results) {
    results.push_back(sofar);

    for (int i = curIdx; i < nums.size(); i++) {
        if (i > curIdx && nums[i] == nums[i - 1])
            continue;

        sofar.push_back(nums[i]);

        recur_subsetWithDup(i + 1, nums, sofar, results);

        sofar.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> sofar;
    vector<vector<int>> results;
    sort(nums.begin(), nums.end());
    recur_subsetWithDup(0, nums, sofar, results);

    return results;
}
};