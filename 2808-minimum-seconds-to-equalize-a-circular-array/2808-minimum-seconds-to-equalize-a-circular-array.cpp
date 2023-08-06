class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int n = nums.size() - 1;
    int mn = INT32_MAX;
    for (auto kvp : mp) {
        int sz = kvp.second.size() - 1;
        int mx_cnt = ((kvp.second[0] - 0) + (n - kvp.second[sz]) + 1) / 2;
        for (int i = 1; i <= sz; i++) {
            int cnt = ((kvp.second[i] - kvp.second[i - 1]) / 2);
            mx_cnt = max(mx_cnt, cnt);
        }
        mn = min(mx_cnt, mn);
    }

    return mn;
    }
};