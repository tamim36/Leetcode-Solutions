class Solution {
public:
    int count_setBits_ByFlipping(int n) {
    int count = 0;
    while (n) {
        n = n & n - 1;
        count++;
    }

    return count;
}

// 338
vector<int> countBits(int n) {
    vector<int> res(n + 1);

    for (int i = 0; i <= n; i++) {
        res[i] = count_setBits_ByFlipping(i);
    }

    return res;
}
};