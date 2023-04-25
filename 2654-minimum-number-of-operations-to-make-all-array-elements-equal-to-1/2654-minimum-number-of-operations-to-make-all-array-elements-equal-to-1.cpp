class Solution {
public:
    int find_gcd(int a, int b) {
    return a == 0 ? b : find_gcd(b % a, a);
}

int minOperations(vector<int>& nums) {
    int minv = INT32_MAX, ones = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) ones++;
    }

    if (ones) return n - ones;

    for (int i = 0; i < n; i++) {
        int g = nums[i];
        for (int j = i + 1; j < n; j++) {
            g = find_gcd(g, nums[j]);
            if (g == 1) {
                minv = min(minv, (j - i + n-1));
                break;
            }
        }
    }

    return minv == INT32_MAX ? -1 : minv;
}
};