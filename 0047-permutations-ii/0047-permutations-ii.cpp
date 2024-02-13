class Solution {
public:
    void recur_permuteUnique(unordered_map<int, int>& umap, vector<vector<int>>& ans, vector<int>& soFar, int n) {
    if (soFar.size() == n) {
        ans.push_back(soFar);
        return;
    }

    for (auto &kvp : umap) {
    if (!kvp.second)
        continue;

    kvp.second--;
    soFar.push_back(kvp.first);
    recur_permuteUnique(umap, ans, soFar, n);
    kvp.second++;
    soFar.pop_back();
}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int, int> umap;
    for (auto num : nums)
        umap[num]++;

    vector<vector<int>> ans;
    vector<int> soFar;
    recur_permuteUnique(umap, ans, soFar, nums.size());

    return ans;
}
};