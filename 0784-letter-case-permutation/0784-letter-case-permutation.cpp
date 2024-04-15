class Solution {
public:
    void recur_letterCasePermutation(int curIdx, string s, vector<string>& res) {
    if (curIdx >= s.size()) {
        //cout << s << endl;
        res.push_back(s);
        return;
    }

    if (isdigit(s[curIdx])) {
        recur_letterCasePermutation(curIdx + 1, s, res);
    }
    else {
        char lowerCase = tolower(s[curIdx]);
        char upperCase = toupper(s[curIdx]);

        string lower = s;
        string upper = s;
        lower[curIdx] = lowerCase;
        upper[curIdx] = upperCase;
        recur_letterCasePermutation(curIdx + 1, lower, res);
        recur_letterCasePermutation(curIdx + 1, upper, res);
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> res;
    if (s.empty())
        return res;

    recur_letterCasePermutation(0, s, res);
    return res;
}
};