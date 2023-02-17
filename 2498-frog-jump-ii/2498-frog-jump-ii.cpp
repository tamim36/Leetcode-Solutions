class Solution {
public:
    int maxJump(vector<int>& stones) {
        int mx = 0, n = stones.size();

    for (int i = 1; i < n - 1; i++) {
        mx = max(mx, max(stones[i]-stones[i-1], stones[i+1]-stones[i-1]));
    }
    // for last element
    mx = max(mx, (stones[n-1] - stones[n-2]));

    return mx;
    }
};