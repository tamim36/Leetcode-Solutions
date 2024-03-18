class Solution {
public:
    void recur_combinationSum3(int curIdx, int k, int n, vector<int>& sofar, vector<vector<int>>& ans) {
    if (n < 0) return;
    if (n == 0) {
        if (sofar.size() == k)
            ans.push_back(sofar);
        return;
    }

    for (int i = curIdx; i <= 9; i++) {
        sofar.push_back(i);

        recur_combinationSum3(i + 1, k, n - i, sofar, ans);

        sofar.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> sofar;
    vector<vector<int>> ans;

    recur_combinationSum3(1, k, n, sofar, ans);

    return ans;
}
};