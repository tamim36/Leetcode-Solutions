class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pref(arr.size() + 1), ans;
pref[0] = 0;

for (int i = 1; i < arr.size() + 1; i++) {
    pref[i] = pref[i - 1] ^ arr[i - 1];
}

for (int i = 0; i < queries.size(); i++) {
    int l = queries[i][0], r = queries[i][1];
    ans.push_back(pref[l] ^ pref[r + 1]);
}

return ans;
    }
};