class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1 || weights.size() == k) return 0;

    long long mx = 0, mn = 0;
    vector<int> pair_sum;
    
    for (int i = 1; i < weights.size(); i++) {
        pair_sum.push_back(weights[i] + weights[i-1]);
    }

    sort(pair_sum.begin(), pair_sum.end());
    for (int i = 0; i < k - 1; i++) mn += pair_sum[i];
    for (int i = pair_sum.size() - 1; i > pair_sum.size() - k; i--) mx += pair_sum[i];
    return mx - mn;
    }
};