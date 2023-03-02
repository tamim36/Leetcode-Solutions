class Solution {
public:
    bool isMaxDistance(vector<int>& pos, int mid, int m) {
    int cnt = 1, prev = pos[0];

    for (int i = 1; i < pos.size() && (m - cnt) <= (pos.size() - i); i++) {
        if (pos[i] - prev >= mid) {
            prev = pos[i];
            ++cnt;
        }
    }

    return cnt >= m;
}

int maxDistance(vector<int>& pos, int m) {
    if (m == 2) {
        return *max_element(pos.begin(), pos.end()) - *min_element(pos.begin(), pos.end());
    }

    sort(pos.begin(), pos.end());
    int left = 1, right = pos[pos.size() - 1];

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (!isMaxDistance(pos, mid, m))
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}
};