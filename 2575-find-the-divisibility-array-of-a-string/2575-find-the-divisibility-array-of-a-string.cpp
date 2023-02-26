class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
    int num = 0, dig = 0;
    long long rem = 0;
    for (auto c : word) {
        dig = c - '0';
        rem = (rem * 10 + dig) % m;
        if (rem == 0) ans.push_back(1);
        else ans.push_back(0);
    }
    return ans;
    }
};