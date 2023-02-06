class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int, int> cnt;
    for (auto c : b1) cnt[c]++;
    for (auto c : b2) cnt[c]--;
    vector<int> vec;

    for (auto &[k, v] : cnt) {
        if (v % 2) return -1;

        for (int i = 0; i < abs(v) / 2; i++)
            vec.push_back(k);
    }

    int minX = min(*min_element(b1.begin(), b1.end()), *min_element(b2.begin(), b2.end()));
    sort(vec.begin(), vec.end());

    long long res = 0;
    for (int i = 0; i < vec.size() / 2; i++)
        res += min(vec[i], minX * 2);

    return res;
    }
};