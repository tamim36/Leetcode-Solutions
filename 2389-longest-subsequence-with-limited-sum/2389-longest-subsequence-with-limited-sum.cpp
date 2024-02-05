class Solution {
public:
    int ansQuery_BinarySearch(vector<int>& nums, int val) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > val)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> prefix, ans;

    for (int i = 0; i < n; i++) {
        int val = nums[i];
        val += prefix.empty() ? 0 : prefix.back();
        prefix.push_back(val);
    }

    for (auto q : queries) {
        ans.push_back(ansQuery_BinarySearch(prefix, q));
    }

    return ans;
}
};