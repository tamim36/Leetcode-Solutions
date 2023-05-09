class Solution {
public:
    int resDfs = 0;
int dfsminIncrements2(vector<int>& cost, int i) {
    if (i >= cost.size()) return 0;

    int l = dfsminIncrements2(cost, 2 * i + 1);
    int r = dfsminIncrements2(cost, 2 * i + 2);

    resDfs += abs(l - r);

    return cost[i] + max(l, r);
}

int minIncrements(int n, vector<int>& cost) {
    dfsminIncrements2(cost, 0);
    return resDfs;
}
};