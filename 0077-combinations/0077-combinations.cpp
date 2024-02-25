class Solution {
public:
    void recur_combine(int n, int k, int cur, vector<int>& sofar, vector<vector<int>>& ans) {
    if (sofar.size() == k) {
        ans.push_back(sofar);
        return;
    }

    for (int i = cur; i <= n; i++) {
        sofar.push_back(i);

        recur_combine(n, k, i+1, sofar, ans);

        sofar.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> sofar;
    vector<vector<int>> ans;

    recur_combine(n, k, 1, sofar, ans);
    return ans;
}
};