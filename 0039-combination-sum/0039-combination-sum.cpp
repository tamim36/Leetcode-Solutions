class Solution {
public:
    void recur_combinationSum(int curSum, int curIdx, vector<int>& candidates, int target, vector<int>& sofar, vector<vector<int>>& ans) {
    if (curSum >= target) {
        if (curSum == target)
            ans.push_back(sofar);

        return;
    }

    for (int i = curIdx; i < candidates.size(); i++) {
        curSum += candidates[i];
        sofar.push_back(candidates[i]);

        recur_combinationSum(curSum, i, candidates, target, sofar, ans);

        sofar.pop_back();
        curSum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> sofar;
    vector<vector<int>> ans;

    recur_combinationSum(0, 0, candidates, target, sofar, ans);

    return ans;
}
};