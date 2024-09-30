class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
int cnt = 0;

for (int i = 1, j = 0; j < piles.size() / 3; i += 2, j++) {
    cnt += piles[i];
}

return cnt;
    }
};