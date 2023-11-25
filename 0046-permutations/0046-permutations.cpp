class Solution {
public:
    void recursePermute(vector<int>& sofar, vector<int>& nums, vector<vector<int>>& ans, int sz) {
    if (sz == sofar.size()) {
        ans.push_back(sofar);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        sofar.push_back(nums[i]);
        vector<int> new_choices(nums);
        new_choices.erase(new_choices.begin() + i);

        recursePermute(sofar, new_choices, ans, sz);

        sofar.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> sofar;
    recursePermute(sofar, nums, ans, nums.size());
    return ans;
}
};