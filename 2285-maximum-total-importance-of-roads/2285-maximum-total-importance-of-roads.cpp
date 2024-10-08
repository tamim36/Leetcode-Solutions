class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> cnt(n + 1);
           long long res = 0;
    for (auto &r : roads) {
        ++cnt[r[0]];
        ++cnt[r[1]];
    }
    sort(begin(cnt), begin(cnt) + n);
    for (int i = 0; i < n; ++i)
        res += ((long long)cnt[i] * (long long)(i + 1));
    return res;
    }
};