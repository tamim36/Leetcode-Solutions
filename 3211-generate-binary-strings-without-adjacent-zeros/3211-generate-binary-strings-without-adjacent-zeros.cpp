class Solution {
public:
    void recurValidString(int n, string curStr, vector<string>& ans) {
    if (curStr.size() == n) {
        ans.push_back(curStr);
        return;
    }

    if (curStr.empty() || curStr.back() == '1')
        recurValidString(n, curStr + "0", ans);

    recurValidString(n, curStr + "1", ans);
}

vector<string> validStrings(int n) {
    vector<string> ans;
    recurValidString(n, "", ans);

    return ans;
}
};