class Solution {
public:
    string vectorTostring(vector<int> vec) {
    sort(vec.begin(), vec.end());
    string s = "";
    for (auto val : vec)
        s += to_string(val);

    return s;
}

void recur_combinationSum2(int curIdx, int curSum, vector<int>& candidates, 
                            int target, vector<int> sofar, vector<vector<int>>& ans, set<string>& isExist, set<string>& checker) {
    if (curSum >= target) {
        if (curSum == target) {
            string val = vectorTostring(sofar);
            if (!isExist.count(val)) {
                ans.push_back(sofar);
                isExist.insert(val);
            }
        }
        return;
    }

    for (int i = curIdx; i < candidates.size(); i++) {
        curSum += candidates[i];
        sofar.push_back(candidates[i]);
        if (!checker.count(vectorTostring(sofar))){
            recur_combinationSum2(i + 1, curSum, candidates, target, sofar, ans, isExist, checker);
        }
    

        checker.insert(vectorTostring(sofar));
        curSum -= candidates[i];
        sofar.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sofar;
    set<string> isExist;
    set<string> checker;
    recur_combinationSum2(0, 0, candidates, target, sofar, ans, isExist, checker);
    return ans;
}
};