class Solution {
public:
    int isValidMaxTastiness(vector<int>& price, int val, int k) {
    int count = 1, prev_val = price[0];
    for (int i = 1; i < price.size(); i++) {
        if (abs(prev_val - price[i]) >= val) {
            prev_val = price[i];
            count++;
        }
        if (count >= k) return true;
    }
    return false;
}

int maximumTastiness(vector<int>& price, int k) {
    int left = 1, right = 1000000000;
    sort(price.begin(), price.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValidMaxTastiness(price, mid, k)) {
            left = mid + 1;
        }
        else
            right = mid;
    }
    return left - 1;
}
};